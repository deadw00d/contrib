#ifndef lint
static char *RCSid = "$Id$";
#endif

/*
 *  The Regina Rexx Interpreter
 *  Copyright (C) 1992-1994  Anders Christensen <anders@pvv.unit.no>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "rexx.h"
#include <string.h>
#include <stdio.h>
#include <signal.h>

#ifdef VMS
# ifndef SIG_ERR
#  define SIG_ERR BADSIG
# endif
#endif

/* at least dolphin does not have a properly ANSI C set of include files */
#ifndef SIG_ERR
# define SIG_ERR ((void(*)())(-1))
#endif

const char *signalnames[] = {
   "ERROR",
   "FAILURE",
   "HALT",
   "NOVALUE",
   "NOTREADY",
   "SYNTAX"
} ;

#ifdef TRACEMEM
void mark_signals( const tsd_t *TSD )
{
   if (TSD->nextsig)
   {
      markmemory( TSD->nextsig, TRC_MATH ) ;
      if (TSD->nextsig->descr)
         markmemory( TSD->nextsig->descr, TRC_MATH ) ;
   }
}
#endif


static trap *dupltraps( const tsd_t *TSD, const trap *traps )
{
   trap *ptr=NULL ;
   int i=0 ;

   ptr = MallocTSD(sizeof(trap) * SIGNALS) ;
   /* Stupid SunOS acc gives incorrect warning for the next line */
   memcpy( ptr, traps, sizeof(trap) * SIGNALS) ;
   for ( i=0; i<SIGNALS; i++ )
      if (traps[i].name)
         ptr[i].name = Str_dupTSD( traps[i].name ) ;


   return ptr ;
}


sigtype *getsigs( proclevel level )
{
   for (; level && (!level->sig); level=level->prev ) ;
   return ((level) ? (level->sig) : (NULL)) ;
}

trap *gettraps( const tsd_t *TSD, proclevel level )
{
   proclevel ptr=level ;

   if (!ptr->traps)
   {
      for (ptr=level; ptr && ptr->traps==NULL; ptr=ptr->prev ) ;
      if (ptr==NULL || ptr->traps==NULL)
         exiterror( ERR_INTERPRETER_FAILURE, 1, __FILE__, __LINE__, "" )  ;

      level->traps = dupltraps( TSD, ptr->traps ) ;
      ptr = level ;
   }

   return ptr->traps ;
}


int condition_hook( tsd_t *TSD, int type, int errorno, int suberrorno, int lineno, streng *description, streng *condition_description )
{
   trap *traps;
   sigtype *sigptr=NULL ;

   traps = gettraps( TSD, TSD->currlevel ) ;
   /* if we dont know what to do, ... or */
   /* if we don't *really* want to try to recover from these ... */
   if (traps==NULL || type == SIGNAL_FATAL)
   {
      if (description)
         Free_stringTSD( description ) ;
      return 0 ;
   }

   if (lineno==(-1))
   {
      if (TSD->currentnode)
         lineno = TSD->currentnode->lineno ;
      else
#ifdef NDEBUG
         lineno = 0 ;
#else
         exiterror( ERR_INTERPRETER_FAILURE, 1, __FILE__, __LINE__, "" )  ;
#endif
   }
   if ( traps[type].on_off) /* condition is being trapped */
   {
      if ((traps[type].delayed) && (traps[type].ignored))
      {
         if (description)
            Free_stringTSD( description ) ;
         return 0 ;
      }

      sigptr = MallocTSD( sizeof( sigtype )) ;

      sigptr->type = type ;
      sigptr->info = NULL ;   /* BUG: I don't really think this is used */
#if 0
      sigptr->descr = description ;
#else
      if (condition_description)
         sigptr->descr = condition_description ;
      else
         sigptr->descr = description ;
#endif
      sigptr->invoke = traps[type].invoked ;
      sigptr->rc = errorno ;
      sigptr->subrc = suberrorno ;
      sigptr->lineno = lineno ;

      if ( traps[type].invoked )   /* if SIGNAL ON */
      {
      /* traps[type].on_off = 0 ;  */ /* turn trap off */
      /* traps[type].trapped = 0 ; */ /* unecessary, just to be sure */
         traps[type].delayed = 0 ;    /* ... ditto ... */
         setvalue( TSD, &SIGL_name, int_to_streng( TSD, lineno )) ;
         if (type == SIGNAL_SYNTAX) /* special condition */
            setvalue( TSD, &RC_name, int_to_streng( TSD, errorno )) ;

         TSD->nextsig = sigptr ;

         if (TSD->in_protected)
         {
            TSD->delayed_error_type = PROTECTED_DelayedSetjmpBuf;
            longjmp( TSD->protect_return, 1 ) ;
         }
         longjmp( *(TSD->currlevel->buf), 1 ) ;
      }
      else
      {
        TSD->nextsig = sigptr ;
        return 1 ;
      }
   }

   if (description)
      Free_stringTSD(description) ;

   /* signal is not to be trapped */
   return (traps[type].def_act) ;
}


int identify_trap( int type )
{
   switch (type)
   {
      case X_S_HALT:     return SIGNAL_HALT ;
      case X_S_SYNTAX:   return SIGNAL_SYNTAX ;
      case X_S_NOVALUE:  return SIGNAL_NOVALUE ;
      case X_S_NOTREADY: return SIGNAL_NOTREADY ;
      case X_S_ERROR:    return SIGNAL_ERROR ;
      case X_S_FAILURE:  return SIGNAL_FAILURE ;
   }
   exiterror( ERR_INTERPRETER_FAILURE, 1, __FILE__, __LINE__, "" )  ;
   return SIGNAL_FATAL ;
}


/* the rest should probably also be defined */
static const char *signals_names[] = {
     "", "SIGHUP", "SIGINT", "", "", "", "", "", "", "",
     "", "", "", "", "", "SIGTERM", "", "", "", "", "",
     "", "", "", "", "", "", "", "", "", "",
     "", ""
} ;

#if defined (HAVE_SIGACTION) && defined(SA_RESTART) && defined(HAVE__SIGHANDLER_T)
/* Most things only works if a signal doesn't break the current system call.
 * sigaction has such a flag and should always been preferred. It has an
 * exactlier defined standard.
 * Defining a "signal()" here also overwrites signal calls in the whole
 * program. FGC
 */
signal_handler regina_signal(int signum,__sighandler_t action)
{
   struct sigaction nsig,osig;

   nsig.sa_handler = action;
   sigemptyset(&nsig.sa_mask);
   nsig.sa_flags = SA_RESTART;
   if (sigaction(signum,&nsig,&osig) != 0)
      return(SIG_ERR);
   return(osig.sa_handler);
}
#elif defined(__AROS__)
signal_handler regina_signal(int signum,signal_handler action)
{
  return SIG_ERR;
}
#else
signal_handler regina_signal(int signum,signal_handler action)
{
# if defined(__WINS__) || defined(__EPOC32__)
   return 0;
# else
   return( signal ( signum, action ) ) ;
# endif
}
#endif

/* Yuk! Some of these should *really* have been volatilized */
static void halt_handler( int num )
{
   tsd_t *TSD = __regina_get_tsd(); /* The TSD must be fetched directly. */

#ifdef VMS
   vms_killproc( TSD ) ;
#endif

   if (regina_signal( num, halt_handler ) == SIG_ERR)
      exiterror( ERR_SYSTEM_FAILURE, 0 )  ;

   if (!condition_hook(TSD,
                       SIGNAL_HALT,
                       ERR_PROG_INTERRUPT,
                       0,
                       lineno_of(TSD->currentnode),
                       Str_creTSD(signals_names[num]),
                       NULL
                       ))
      exiterror( ERR_PROG_INTERRUPT, 0 )  ;

   return ;
}

#if !defined(__WINS__) && !defined(__EPOC32__)
# if defined(SIGHUP)
static void hup_handler( int dummy )
{
   tsd_t *TSD = __regina_get_tsd();

   if (TSD->in_protected)
   {
      TSD->delayed_error_type = PROTECTED_DelayedExit;
      TSD->expected_exit_error = 0;
      longjmp( TSD->protect_return, 1 ) ;
   }
   TSD->MTExit( 0 ) ;
}
# endif
#endif


void signal_setup( const tsd_t *TSD )
{
   TSD = TSD; /* keep compiler happy */

/*
 * EPOC32 does not have signal()!!
 * AROS at the moment also lacks signal
 */
#if !defined(__WINS__) && !defined(__EPOC32__) && !defined(__AROS__)
# if defined(SIGTERM)
   if (regina_signal( SIGTERM, halt_handler ) == SIG_ERR)
      exiterror( ERR_SYSTEM_FAILURE, 0 )  ;
# endif
# if defined(SIGINT)
   if (regina_signal( SIGINT, halt_handler) == SIG_ERR)
      exiterror( ERR_SYSTEM_FAILURE, 0 )  ;
# endif
# if defined(SIGHUP)
   if (regina_signal( SIGHUP, (TSD->isclient)?(hup_handler):(halt_handler)) == SIG_ERR)
      exiterror( ERR_SYSTEM_FAILURE, 0 )  ;
# endif
#endif
}

void set_rexx_halt( void )
{
   halt_handler( SIGINT );
}



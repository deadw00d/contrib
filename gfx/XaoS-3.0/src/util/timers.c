/* 
 *     XaoS, a fast portable realtime fractal zoomer 
 *                  Copyright (C) 1996,1997 by
 *
 *      Jan Hubicka          (hubicka@paru.cas.cz)
 *      Thomas Marsh         (tmarsh@austin.ibm.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * All ugly architecture depended timing code is separated into this file..
 */

#ifdef _plan9_
#include <u.h>
#include <stdio.h>
#include <libc.h>
#else
#include <aconfig.h>

#ifndef AROS
#include <malloc.h>
#endif

#include <stdio.h>
#include <unistd.h>

#if !defined(_MAC) && !defined(AROS)
#include <malloc.h>
#endif

#ifdef __BEOS__
#include <OS.h>
#endif

#ifdef USE_ALLEGRO
#include <allegro.h>
#endif

#ifdef HAVE_SETITIMER
#include <signal.h>
#endif

#ifndef AROS
#include <limits.h>
#endif

#endif

#ifndef _plan9_
#include <assert.h>
#endif
#include <timers.h>
#ifdef USE_ALLEGRO
int allegromode;
#define TICKSPERSEC 100		/*must be divisor of 1000000 */
volatile static int counter = -1;
static int ainstalled;
#endif
#ifdef HAVE_UCLOCK
static uclock_t currenttime;
#else
#ifdef USE_CLOCK
static int currenttime;
#else
#ifdef HAVE_GETTIMEOFDAY
static struct timeval currenttime;
#ifdef __AMIGAOS__
extern long __timezone;
#define tzp __timezone
#else
static struct timezone tzp;
#endif
#else
#ifdef HAVE_FTIME
static struct timeb currenttime;
#endif
#endif
#endif
#endif
#ifdef _plan9_
static int currenttime;
#endif
static int registered = 0, reghandler = 0;
static tl_group group1, group2;
tl_group *syncgroup = &group1,
#ifdef HAVE_SETITIMER
 *asyncgroup = &group2;
#else
 *asyncgroup = &group1;
#endif
#ifdef _plan9_
static int
plan9_msec (void)
{				/*this function was sent by Nigel Roles */
  static int fd = -1;
  char buf[20];			/* ish */
  if (fd < 0)
    fd = open ("/dev/msec", OREAD);
  else
    seek (fd, 0, 0);
  read (fd, buf, sizeof (buf));
  return atoi (buf);
}
#endif

#ifndef HAVE_GETTIMEOFDAY
#ifndef HAVE_FTIME
#ifndef _plan9_
#error I am unable to get time in milisecond. Please edit timers.c and make tl_update_time and tl_lookup_timer to work for your architecture and send me then back(to hubicka@paru.cas.cz). You will need also define timers.h and change type of lasttime.
#endif
#endif
#endif
#ifdef USE_ALLEGRO
static void
timer (void)
{
  counter++;
}
END_OF_FUNCTION (timer);
#endif
/*following functions are architecture dependent */
void
tl_update_time (void)
{
#ifdef USE_ALLEGRO
  if (allegromode)
    {
      if (counter == -1)
	{
	  LOCK_VARIABLE (counter);
	  LOCK_FUNCTION (timer);
	  install_int (timer, 1000 / TICKSPERSEC);
	  ainstalled = 1;
	  counter = 0;
	}
      currenttime = counter;
      return;
    }
#endif
#ifdef HAVE_UCLOCK
  currenttime = uclock ();
#else
#ifdef USE_CLOCK
  currenttime = clock ();
#else
#ifdef HAVE_GETTIMEOFDAY
  do
    {
      gettimeofday (&currenttime, &tzp);
    }
  while (currenttime.tv_usec > 999999);
#else
#ifdef HAVE_FTIME
  ftime (&currenttime);
#endif
#endif
#endif
#endif
#ifdef _plan9_
  currenttime = plan9_msec ();
#endif
}

static INLINE int
__lookup_timer (tl_timer * t)
{
#ifdef USE_ALLEGRO
  if (allegromode)
    return (((currenttime - t->lastactivated) * (1000000LL / TICKSPERSEC)));
#endif
#ifdef HAVE_UCLOCK
  return (((currenttime - t->lastactivated) * 1000000LL) / UCLOCKS_PER_SEC);
#else
#ifdef USE_CLOCK
  return ((currenttime - t->lastactivated) * (1000000.0 / CLOCKS_PER_SEC));
#else
#ifdef HAVE_GETTIMEOFDAY
  return ((1000000 * (-t->lastactivated.tv_sec + currenttime.tv_sec) + (-t->lastactivated.tv_usec + currenttime.tv_usec)));
#else
#ifdef HAVE_FTIME
  return ((1000000 * (-t->lastactivated.time + currenttime.time) + 1000 * (-t->lastactivated.millitm + currenttime.millitm)));
#else
#ifdef _plan9_
  return ((currenttime - t->lastactivated) * 1000);
#endif
#endif
#endif
#endif
#endif
}
int
tl_lookup_timer (tl_timer * t)
{
  if (t->stopped)
    {
      return (t->stoppedtime);
    }
  return (__lookup_timer (t) - t->slowdown);
}
void
tl_stop_timer (tl_timer * t)
{
  if (!t->stopped)
    {
      t->stoppedtime = tl_lookup_timer (t);
      t->stopped = 1;
    }
}
void
tl_slowdown_timer (tl_timer * t, int time)
{
  if (!t->stopped)
    {
      t->slowdown += time;
    }
  else
    t->stoppedtime -= time;
}
void
tl_resume_timer (tl_timer * t)
{
  if (t->stopped)
    {
      t->stopped = 0;
      t->slowdown = __lookup_timer (t) - t->stoppedtime;
    }
}
void
tl_sleep (int time)
{
#ifdef HAVE_USLEEP
  usleep (time);
#else
#ifdef HAVE_SELECT
  {
    struct timeval tv;
    tv.tv_sec = time / 1000000L;
    tv.tv_usec = time % 1000000L;
    (void) select (0, (void *) 0, (void *) 0, (void *) 0, &tv);
  }
#else
#ifdef _plan9_
  sleep (time / 1000);
#else
#ifdef __BEOS__
  snooze(time);
#else
/*
   #warning tl_sleep function not implemented. You may ignore this warning.
   #warning xaos will work correctly. But on miltitasked enviroments it is
   #warning HIGHLY recomended to implement this.
 */
#endif
#endif
#endif
#endif
}

void
tl_reset_timer (tl_timer * t)
{
  if (t->stopped)
    t->stoppedtime = 0;
  else
    t->lastactivated = currenttime,
    t->slowdown = 0;
}

tl_timer *
tl_create_timer (void)
{
  tl_timer *timer;
  timer = (tl_timer *) malloc (sizeof (tl_timer));
  if (timer == NULL)
    return NULL;
  timer->interval = -1;
  timer->handler = NULL;
  timer->multihandler = NULL;
  timer->userdata = NULL;
  timer->next = NULL;
  timer->previous = NULL;
  timer->group = NULL;
  timer->stopped = 0;
  timer->stoppedtime = 0;
  timer->slowdown = 0;
  tl_reset_timer (timer);
  return (timer);
}
tl_group *
tl_create_group (void)
{
  tl_group *timer;
  timer = (tl_group *) malloc (sizeof (tl_group));
  if (timer == NULL)
    return NULL;
  timer->interval = -1;
  timer->handler = NULL;
  timer->multihandler = NULL;
  timer->userdata = NULL;
  timer->next = NULL;
  timer->previous = NULL;
  timer->group = timer;
  tl_reset_timer (timer);
  return (timer);
}


void
tl_free_timer (tl_timer * timer)
{
  if (timer->group)
    tl_remove_timer (timer);
  free ((void *) timer);
}

void
tl_free_group (tl_group * timer)
{
  tl_timer *next;
  do
    {
      next = timer->next;
      free ((void *) timer);
    }
  while (next != NULL);
}
int
tl_process_group (tl_group * group, int *activated)
{
  int again = 1;
  tl_timer *timer, *timer1;
  int minwait = INT_MAX;
  tl_update_time ();
  if (activated != NULL)
    *activated = 0;
  while (again)
    {
      again = 0;
      minwait = INT_MAX;
      timer = group->next;
      while (timer != NULL)
	{
	  timer1 = timer->next;
	  if (timer->handler && timer->interval >= 0)
	    {
	      int time = timer->interval - tl_lookup_timer (timer);
	      if (time < 500)
		{
		  if (activated != NULL)
		    (*activated)++;
		  again = 1;
		  tl_reset_timer (timer);
		  if (time < -200 * 1000000)
		    time = 0;	/*underflow? */
		  tl_slowdown_timer (timer, time);
		  time = timer->interval + time;
		  timer->handler (timer->userdata);
		  tl_update_time ();
		}
	      if (time < minwait)
		minwait = time;
	    }
	  else if (timer->multihandler && timer->interval > 0)
	    {
	      int time = timer->interval - tl_lookup_timer (timer);
	      if (time < 500)
		{
		  int n;
		  if (activated != NULL)
		    (*activated)++;
		  tl_reset_timer (timer);
		  if (time < -200 * 1000000)
		    time = 0;	/*underflow? */
		  n = -(time + 500) / timer->interval + 1;
		  time = timer->interval * n + time;
		  tl_slowdown_timer (timer, time - timer->interval + n * timer->interval);
		  timer->multihandler (timer->userdata, n);
		  tl_update_time ();
		}
	      if (time < minwait)
		minwait = time;
	    }
	  timer = timer1;
	}
    }
  if (minwait != INT_MAX)
    {
      if (minwait < 0)
	return (0);
      return (minwait);
    }
  return (-1);
}
#ifdef HAVE_SETITIMER
static void update_async (void);
static void
alarmhandler (int a)
{
  update_async ();
  signal (SIGALRM, alarmhandler);
}
static void
update_async ()
{
  int time = tl_process_group (asyncgroup, NULL);
  if (time != -1)
    {
      struct itimerval t;
      t.it_interval.tv_sec = 0;
      t.it_interval.tv_usec = 0;
      t.it_value.tv_sec = time / 1000000;
      t.it_value.tv_usec = time % 1000000;
      if (!reghandler)
	{
	  signal (SIGALRM, alarmhandler), reghandler = 1;
	}
      setitimer (ITIMER_REAL, &t, &t);
      registered = 1;
    }
  else if (registered)
    {
      struct itimerval t;
      t.it_interval.tv_sec = 0;
      t.it_interval.tv_usec = 0;
      t.it_value.tv_sec = 0;
      t.it_value.tv_usec = 0;
      setitimer (ITIMER_REAL, &t, &t);
      registered = 0;
    }
}

#else
#define update_async()
#endif
void
tl_add_timer (tl_group * group, tl_timer * timer)
{
  if (timer->group)
    tl_remove_timer (timer);
  timer->previous = group;
  timer->next = group->next;
  timer->group = group;
  group->next = timer;
  if (timer->group == asyncgroup)
    update_async ();
}
void
tl_set_interval (tl_timer * timer, int interval)
{
  if (timer->interval <= 0)
    {
      tl_reset_timer (timer);
    }
  timer->interval = interval;
  if (timer->group == asyncgroup)
    update_async ();
}

void
tl_set_handler (tl_timer * timer, void (*handler) (void *), void *ud)
{
  timer->handler = handler;
  timer->userdata = ud;
  if (timer->group == asyncgroup)
    update_async ();
}
void
tl_set_multihandler (tl_timer * timer, void (*handler) (void *, int), void *ud)
{
  timer->multihandler = handler;
  timer->userdata = ud;
  if (timer->group == asyncgroup)
    update_async ();
}

void
tl_remove_timer (tl_timer * timer)
{
  tl_group *g = timer->group;
  timer->previous->next = timer->next;
  if (timer->next != NULL)
    timer->next->previous = timer->previous;
  timer->group = NULL;
  if (g == asyncgroup)
    update_async ();
}
#ifdef USE_ALLEGRO
void
tl_allegromode (int mode)
{
  allegromode = mode;
  if (!allegromode && ainstalled)
    {
      remove_int (timer);
      ainstalled = 0;
      counter = -1;
    }
}
#endif

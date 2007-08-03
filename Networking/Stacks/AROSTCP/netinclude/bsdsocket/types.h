#ifndef BSDSOCKET_TYPES_H
#define BSDSOCKET_TYPES_H
/*
 * $Id$
 *
 * Common types previously defined in multiple headers.
 *
 * Copyright (c) 1994 AmiTCP/IP Group, <amitcp-group@hut.fi>
 *                    Helsinki University of Technology, Finland.
 *                    All rights reserved.
 * 
 *       Created: Thu Apr  7 22:50:12 1994 jraja
 * Last modified: Thu Apr  7 23:19:57 1994 jraja
 *
 * HISTORY
 * $Log: types.h,v $
 * Revision 1.1.1.1  2005/12/07 10:50:36  sonic_amiga
 * First full import into the CVS
 *
 * Revision 1.1  2005/01/20 23:17:04  neil
 * Initial revision.
 *
 * Revision 1.3  2004/12/30 19:52:04  neil
 * Updated copyright notices in includes; other clean-ups.
 *
 * Revision 1.2  2004/12/30 11:15:36  neil
 * Started tidying up netincludes.
 *
 * Revision 1.1.1.1  2004/12/13 07:00:22  neil
 * Imported sources.
 *
 * Revision 3.1  1994/04/07  20:20:16  jraja
 * Initial revision.
 *
 */

#ifndef _UID_T
#define _UID_T long
typedef _UID_T uid_t;
#endif

#ifndef _GID_T
#define _GID_T long
typedef _GID_T gid_t;
#endif

#ifndef _PID_T
#ifdef __AROS__
#define __AROS_PID_T_DECLARED
#endif
#define _PID_T struct Task *
typedef	_PID_T pid_t;			/* process id */
#endif

#ifndef _MODE_T
#define _MODE_T unsigned short 
typedef _MODE_T mode_t;
#endif

#ifndef __AROS_TIME_T_DECLARED
#ifndef _TIME_T
#define _TIME_T long
typedef _TIME_T time_t;
#endif
#endif

#ifndef NULL
#define	NULL 0L
#endif

#endif /* !BSDSOCKET_TYPES_H */

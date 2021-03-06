
#ifndef CLASSBASE_H
#define CLASSBASE_H 1

/*
**
**  $VER: classbase.h 1.11 (7.11.97)
**  mpegvideo.datatype 1.11
**
**  Header file for DataTypes class
**
**  Written 1996/1997 by Roland 'Gizzy' Mainz
**  Original example source from David N. Junod
**
*/

/* amiga includes */
#include <exec/types.h>
#include <exec/ports.h>
#include <exec/memory.h>
#include <exec/lists.h>
#include <exec/semaphores.h>
#include <exec/execbase.h>
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <dos/rdargs.h>
#include <dos/dostags.h>
#include <dos/var.h>
#include <graphics/gfx.h>
#include <graphics/text.h>
#include <graphics/scale.h>
#include <graphics/gfxbase.h>
#if !defined(__AROS__) && !defined(__MORPHOS__)
#include <cybergraphics/cybergraphics.h>
#else
#include <cybergraphx/cybergraphics.h>
#endif
#include <intuition/classes.h>  /* must have Id tag "classes.h,v 40.0 94/02/15 17:46:35 davidj Exp Locker: davidj" */
#include <intuition/classusr.h>
#include <intuition/cghooks.h>
#include <intuition/icclass.h>
#include <intuition/gadgetclass.h>
#include <datatypes/datatypes.h>
#include <datatypes/datatypesclass.h>
#include <datatypes/animationclass.h>
#include <datatypes/animationclassext.h> /* animation.datatype V41 */

/* amiga prototypes */
#ifdef __SASC
#include <clib/macros.h>
#include <clib/exec_protos.h>
#include <clib/utility_protos.h>
#include <clib/dos_protos.h>
#include <clib/graphics_protos.h>
#include <clib/cybergraphics_protos.h>
#include <clib/intuition_protos.h>
#include <clib/datatypes_protos.h>
#include <clib/dtclass_protos.h>
#ifdef PARAMETERS_STACK
#include <clib/alib_stdio_protos.h>
#endif /* PARAMETERS=STACK */

/* amiga pragmas */
#include <pragmas/exec_pragmas.h>
#include <pragmas/utility_pragmas.h>
#include <pragmas/dos_pragmas.h>
#include <pragmas/graphics_pragmas.h>
#include <pragmas/cybergraphics_pragmas.h>
#include <pragmas/intuition_pragmas.h>
#include <pragmas/datatypes_pragmas.h>
#include <pragmas/dtclass_pragmas.h>
#include <pragmas/alib_pragmas.h> /* amiga.lib stubs (tagcall pragmas) */
#else
#include <proto/exec.h>
#include <proto/utility.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <proto/cybergraphics.h>
#include <proto/intuition.h>
#include <proto/datatypes.h>
#include <proto/dtclass.h>
#include <proto/iffparse.h>

#include <clib/alib_protos.h>
#endif

/* ANSI includes */
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

/* VMM support */
#include "vmm.h"

/* project includes */
#include "mpegvideo.h"
#include "mpegamiga.h"

/*****************************************************************************/

#ifndef AFF_68060
#define AFF_68060 (1L<<7)
#endif /* !AFF_68060 */

/*****************************************************************************/

typedef long          INT32;
typedef unsigned long UINT32;

/*****************************************************************************/

#define MPEGVIDEODTCLASS "mpegvideo.datatype"

/*****************************************************************************/

struct ClassBase
{
    struct ClassLibrary     cb_Lib;
#if !defined(__AROS__)
    struct ExecBase        *cb_SysBase;
    struct Library         *cb_UtilityBase;
    struct Library         *cb_VMMBase;
    struct Library         *cb_DOSBase;
    struct GfxBase         *cb_GfxBase;
    struct Library         *cb_CyberGfxBase;
    struct Library         *cb_IntuitionBase;
    struct Library         *cb_DataTypesBase;
    struct Library         *cb_SuperClassBase;
    BPTR                    cb_SegList;
#endif
    struct SignalSemaphore  cb_Lock;           /* Access lock */
};

/*****************************************************************************/

#ifdef __SASC
/* SASC specific defines */
#define REGARGS __asm
#define ASM __asm
#define DISPATCHERFLAGS __saveds __asm
#define REGD0 register __d0
#define REGD1 register __d1
#define REGD2 register __d2
#define REGD3 register __d3
#define REGD4 register __d4
/* ... */
#define REGA0 register __a0
#define REGA1 register __a1
#define REGA2 register __a2
#define REGA3 register __a3
/* ... */
#define REGA6 register __a6
#else
#ifdef __GNUC__
#define DISPATCHERFLAGS
#define ASM
#define REGD0
#define REGA0
#define REGA1
#define REGA2
#define REGA6
#define __stdargs
#else
#error unsupported compiler
#endif
#endif

/*****************************************************************************/

#if !defined(__AROS__)
#define SysBase        (classbase -> cb_SysBase)
#define UtilityBase    (classbase -> cb_UtilityBase)
#define VMMBase        (classbase -> cb_VMMBase)
#define DOSBase        (classbase -> cb_DOSBase)
#define GfxBase        (classbase -> cb_GfxBase)
#define CyberGfxBase   (classbase -> cb_CyberGfxBase)
#define IntuitionBase  (classbase -> cb_IntuitionBase)
#define DataTypesBase  (classbase -> cb_DataTypesBase)
#endif

/*****************************************************************************/

#if defined(__AROS__)
#define ABS(x) x
#define	MIN(a,b) (((a) < (b)) ?	(a) : (b))
#define	MAX(a,b) (((a) > (b)) ?	(a) : (b))
#endif

/* integer division, rounded */
#define INTDIVR( x, y ) (((x) + ((y) / 2)) / (y))

/* Align memory on 4 byte boundary */
#define ALIGN_LONG( mem ) ((APTR)((((IPTR)(mem)) + 3UL) & ~3UL))

/* Align memory on 16 byte boundary */
#define ALIGN_QUADLONG( mem ) ((APTR)((((IPTR)(mem)) + 15UL) & ~15UL))

/* Following ptr */
#define MEMORY_FOLLOWING( ptr )     ((void *)((ptr) + 1))

/* Memory after n bytes */
#define MEMORY_N_FOLLOWING( ptr, n ) ((void *)(((UBYTE *)ptr) + n ))

/* Memory after n bytes, longword aligned (Don't forget the 4 bytes in size for rounding !!) */
#define MEMORY_NAL_FOLLOWING( ptr, n ) (ALIGN_LONG( ((void *)(((UBYTE *)ptr) + n )) ))

/* casts */
#define V( x )    ((VOID *)(x))
#define G( o )    ((struct Gadget *)(o))
#define EXTG( o ) ((struct ExtGadget *)(o))

/* Exclude tag item */
#define XTAG( expr, tagid ) ((Tag)((expr)?(tagid):(TAG_IGNORE)))

/* Get data from pointer only if it is NOT NULL (and cast data to IPTR) */
#define XPTRDATA( x ) ((IPTR)((x)?(*(x)):(0UL)))

/* Boolean conversion */
#define MAKEBOOL( x ) ((BOOL)((x) != 0))

/*****************************************************************************/
/* CyberGFX related stuff */

/* This one is missing in the CyberGFX includes (thanks to Niels Froehling for this) */
#ifndef BMB_SPECIALFMT
#define BMB_SPECIALFMT (7UL)
#define BMF_SPECIALFMT (1UL << BMB_SPECIALFMT)
#endif /* BMB_SPECIALFMT */

#if !defined(__AROS__)
#define SHIFT_PIXFMT( fmt ) (((ULONG)(fmt)) << 24UL)
#endif

#define CYBERGFXNAME     "cybergraphics.library"
#define CYBERGFXVERSION  (40UL)

/*****************************************************************************/

#ifdef __SASC
#ifndef PARAMETERS_STACK
#define PARAMETERS_STACK 1
#define  CLIB_ALIB_PROTOS_H
__stdargs void  NewList( struct List *list );
__stdargs ULONG DoMethodA( Object *obj, Msg message );
__stdargs ULONG DoMethod( Object *obj, unsigned long MethodID, ... );
__stdargs ULONG DoSuperMethodA( struct IClass *cl, Object *obj, Msg message );
__stdargs ULONG DoSuperMethod( struct IClass *cl, Object *obj, unsigned long MethodID, ... );
__stdargs ULONG CoerceMethodA( struct IClass *cl, Object *obj, Msg message );
__stdargs ULONG CoerceMethod( struct IClass *cl, Object *obj, unsigned long MethodID, ... );
__stdargs ULONG SetSuperAttrs( struct IClass *cl, Object *obj, unsigned long Tag1, ... );
#endif /* !PARAMETERS_STACK */
#endif

/*****************************************************************************/

#include "class_iprotos.h"

#endif /* !CLASSBASE_H */



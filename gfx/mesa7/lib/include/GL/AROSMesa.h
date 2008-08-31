/* AROSmesa.h */

/*
 * Mesa 3-D graphics library
 * Version:  1.2
 * Copyright (C) 1995  Brian Paul  (brianp@ssec.wisc.edu)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef AROSMESA_H
#define AROSMESA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <intuition/intuition.h>
#include <GL/gl.h>

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*      Drawmode to use         */

enum AMesaError
{
   AMESA_OUT_OF_MEM = 1,
   AMESA_RASTPORT_TAG_MISSING,
   AMESA_SCREEN_TAG_MISSING,
   AMESA_WINDOW_TAG_MISSING
};



/*
 * This is the AROS/Mesa context structure.  This usually contains
 * info about what window/buffer we're rendering too, the current
 * drawing color, etc.
 */

struct arosmesa_context;

typedef struct arosmesa_context * AROSMesaContext;

/*
 * AROS Mesa Attribute tag ID's.  These are used in the ti_Tag field of
 * TagItem arrays passed to AROSMesaSetDefs() and AROSMesaCreateContext()
 */
#define AMA_Dummy         (TAG_USER + 32)

#define AMA_Context      (AMA_Dummy + 0x0001)

/*
Offset to use. WARNING AMA_Left, AMA_Bottom Specifies the low left corner
of the drawing area in deltapixles from the lowest left corner
typical AMA_Left,window->BorderLeft
        AMA_Bottom,window->BorderBottom + 1
This is since ALL gl drawing actions is specified with this point as 0,0
and with y positive uppwards (like in real graphs).

Untuched (default) will result in 
AMA_Left=0;
AMA_Bottom=0;
*/
#define AMA_Left         (AMA_Dummy + 0x0002)
#define AMA_Right         (AMA_Dummy + 0x0003)
#define AMA_Top          (AMA_Dummy + 0x0004)
#define AMA_Bottom      (AMA_Dummy + 0x0005)

/*
Size in pixels of drawing area if others than the whole rastport.
All internal drawingbuffers will be in this size

Untuched (default) will result in 
AMA_Width =rp->BitMap->BytesPerRow*8;
AMA_Height=rp->BitMap->Rows;
*/
#define AMA_Width         (AMA_Dummy + 0x0006)
#define AMA_Height      (AMA_Dummy + 0x0007)

/*
This may become unneaded, and code to autodetect the gfx-card should be added

AMA_DrawMode: Specifies the drawing hardware and should be one of
              AGA,(CYBERGFX,RETINA)
              default value: AGA
if AMESA_AGA AROS native drawigns
   this has to be filled with data
      AMA_Window = (ptr) Window to draw on
   or
      AMA_Screen =(ptr) Screen to draw on.
      AMA_RastPort =(ptr) RastPort to draw on.

if AMESA_AGA_C2P AROS native drawing using a chunky buffer
             thats converted when switching drawbuffer
             only works on doublebuffered drawings.
   this has to be filled with data
      AMA_DoubleBuf = GL_TRUE
      AMA_Window = (ptr) Window to draw on
   or
      AMA_DoubleBuf = GL_TRUE
      AMA_Screen =(ptr) Screen to draw on.
      AMA_RastPort =(ptr) RastPort to draw on.

else
   here should all needed gfx-card tagitem be specified
*/

enum DrawModeID            {AMESA_AGA,AMESA_AGA_C2P /*,AMESA_CYBERGFX,AMESA_RETINA*/};
#define AMA_DrawMode      (AMA_Dummy + 0x0010)
#define AMA_Screen         (AMA_Dummy + 0x0011)
#define AMA_Window         (AMA_Dummy + 0x0012)
#define AMA_RastPort      (AMA_Dummy + 0x0013)

/** booleans **/
/*
AMA_DoubleBuf: If specified it uses double Buffering (change buffer with
               AROSMesaSwapBuffers()) Turn this on as much as posible
               it will result in smother looking and faster rendering
               default value: GL_FALSE
AMA_RGBMode: If specified it uses 24bit when drawing (on non 24bit displays it
             it emuletes 24bit)
             default value: GL_TRUE
AMA_AlphaFlag: Alphachanel ?
               Defule value: GL_FALSE
*/
#define AMA_DoubleBuf      (AMA_Dummy + 0x0030)
#define AMA_RGBMode         (AMA_Dummy + 0x0031)
#define AMA_AlphaFlag      (AMA_Dummy + 0x0032)

/** Special **/
/*
AMA_ShareGLContext: Set the "friend" context (use multiple contexts) 
                    See the GL maual or Mesa to get more info
AMA_Visual: If you want to implement your own arosmesa_visual 
AMA_Buffer: If you want to implement your own arosmesa_buffer
AMA_WindowID: A windowID to use when I alloc AMA_Buffer for you if
              you didn't supply one.(default=1)
*/

#define AMA_ShareGLContext  (AMA_Dummy + 0x0040)
#define AMA_Visual          (AMA_Dummy + 0x0041)
#define AMA_Buffer          (AMA_Dummy + 0x0042)
#define AMA_WindowID        (AMA_Dummy + 0x0043)

#ifdef __cplusplus
}
#endif

/**********************************************************************/
/*****                  AROS/Mesa API Functions                   *****/
/**********************************************************************/

GLAPI AROSMesaContext GLAPIENTRY AROSMesaCreateContextTags(long Tag1, ...);
GLAPI AROSMesaContext GLAPIENTRY AROSMesaCreateContext(struct TagItem *tagList);
GLAPI void GLAPIENTRY AROSMesaDestroyContext(AROSMesaContext amesa);
GLAPI void GLAPIENTRY AROSMesaMakeCurrent(AROSMesaContext amesa);
GLAPI void GLAPIENTRY AROSMesaSwapBuffers(AROSMesaContext amesa);

#endif /* AROSMESA_H */

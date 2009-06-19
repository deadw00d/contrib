#ifndef MUI_NLISTVIEWS_priv_MCP_H
#define MUI_NLISTVIEWS_priv_MCP_H

/***************************************************************************

 NListviews.mcp - New Listview MUI Custom Class Preferences
 Registered MUI class, Serial Number: 1d51 (0x9d510001 to 0x9d51001F
                                            and 0x9d510101 to 0x9d51013F)

 Copyright (C) 1996-2001 by Gilles Masson
 Copyright (C) 2001-2005 by NList Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 NList classes Support Site:  http://www.sf.net/projects/nlist-classes

 $Id$

***************************************************************************/

#include "amiga-align.h"
#include "NListviews_mcp.h"
#include "default-align.h"

#include "Debug.h"

#include <mcc_common.h>

#define PREFSIMAGEOBJECT \
  BodychunkObject,\
    MUIA_FixWidth,              LIST_WIDTH,\
    MUIA_FixHeight,             LIST_HEIGHT,\
    MUIA_Bitmap_Width,          LIST_WIDTH ,\
    MUIA_Bitmap_Height,         LIST_HEIGHT,\
    MUIA_Bodychunk_Depth,       LIST_DEPTH,\
    MUIA_Bodychunk_Body,        (UBYTE *)list_body,\
    MUIA_Bodychunk_Compression, LIST_COMPRESSION,\
    MUIA_Bodychunk_Masking,     LIST_MASKING,\
    MUIA_Bitmap_SourceColors,   (ULONG *)list_colors,\
    MUIA_Bitmap_Transparent,    0,\
  End

#define MCPMAXRAWBUF 64

struct NListviews_MCP_Data
{
  Object *mcp_group;

  Object *mcp_list1;
  Object *mcp_list2;

  Object *mcp_PenTitle;
  Object *mcp_PenList;
  Object *mcp_PenSelect;
  Object *mcp_PenCursor;
  Object *mcp_PenUnselCur;
  Object *mcp_PenInactive;
  Object *mcp_BG_Title;
  Object *mcp_BG_List;
  Object *mcp_BG_Select;
  Object *mcp_BG_Cursor;
  Object *mcp_BG_UnselCur;
  Object *mcp_BG_Inactive;

  Object *mcp_R_Multi;
  Object *mcp_B_MultiMMB;
  Object *mcp_R_Drag;
  Object *mcp_SL_VertInc;
  Object *mcp_R_HSB;
  Object *mcp_R_VSB;
  Object *mcp_B_Smooth;

  Object *mcp_Font;
  Object *mcp_Font_Little;
  Object *mcp_Font_Fixed;
  Object *mcp_ForcePen;

  Object *mcp_ColWidthDrag;
  Object *mcp_PartialCol;
  Object *mcp_List_Select;
  Object *mcp_NList_Menu;
  Object *mcp_PartialChar;
  Object *mcp_SerMouseFix;
  Object *mcp_DragLines;
  Object *mcp_VerticalCenteredLines;
  Object *mcp_SelectPointer;

  Object *mcp_WheelStep;
  Object *mcp_WheelFast;
  Object *mcp_WheelMMB;

  Object *mcp_listkeys;
  Object *mcp_stringkey;
  Object *mcp_snoopkey;
  Object *mcp_insertkey;
  Object *mcp_removekey;
  Object *mcp_updatekeys;
  Object *mcp_defaultkeys;
  Object *mcp_txtfct;
  Object *mcp_popstrfct;
  Object *mcp_poplistfct;

  struct KeyBinding *nlkeys;
  LONG nlkeys_size;
  char QualifierString[192];

  char rawtext[MCPMAXRAWBUF];
  char **exampleText;

  struct InputEvent ievent;

  WORD pad1,pad2;
};

#define LIBVER(lib) ((struct Library *)lib)->lib_Version

#endif /* MUI_NLISTVIEWS_priv_MCP_H */

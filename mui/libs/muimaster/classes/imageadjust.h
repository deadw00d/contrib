/* 
    Copyright � 2002, The AROS Development Team.
    All rights reserved.

    $Id$
*/

#ifndef _MUI_CLASSES_IMAGEADJUST_H
#define _MUI_CLASSES_IMAGEADJUST_H

#define MUIC_Imageadjust "Imageadjust.mui"

#define MUIA_Imageadjust_Type (TAG_USER|0x00422f2b) /* MUI: V11 i.. LONG */
#define MUIA_Imageadjust_Spec (TAG_USER|0x004279e1) /* MUI: ??? .g. char * */

enum
{
    MUIV_Imageadjust_Type_All = 0,
    MUIV_Imageadjust_Type_Image,
    MUIV_Imageadjust_Type_Background,
    MUIV_Imageadjust_Type_Pen,
};

extern const struct __MUIBuiltinClass _MUI_Imageadjust_desc; /* PRIV */

#endif

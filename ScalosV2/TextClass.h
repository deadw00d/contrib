// :ts=4 (Tabsize)

/*
** Amiga Workbench� Replacement
**
** (C) Copyright 1999,2000 Aliendesign
** Stefan Sommerfeld, J�rg Rebenstorf
**
** Redistribution and use in source and binary forms are permitted provided that
** the above copyright notice and this paragraph are duplicated in all such
** forms and that any documentation, advertising materials, and other
** materials related to such distribution and use acknowledge that the
** software was developed by Aliendesign.
** THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
** WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
** MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
*/
// we need to export our struct instance data because maintask needs its size

struct TextInst
{
        char *string;
        struct TextAttr font;
        UWORD numchars;
        UWORD type;
        ULONG textpen;
        ULONG backpen;
        ULONG outlinepen;
        UWORD apen;                         // real apen to set with SetAPen
        UWORD bpen;                         // real bpen
        UWORD open;                         // real outline pen
        UBYTE style;
};


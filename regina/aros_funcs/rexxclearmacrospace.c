/*
    (C) 2001 AROS - The Amiga Research OS
    $Id$

    Desc: Regina function RexxClearMacroSpace()
    Lang: English
*/

#include "regina_intern.h"

/*****************************************************************************

    NAME */

	AROS_LH0(APIRET, RexxClearMacroSpace,

/*  SYNOPSIS */

/*  LOCATION */
	struct Library *, ReginaBase, 29, Regina)

/*  FUNCTION
        RexxClearMacroSpace function from Rexx SAA library

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct Library *,ReginaBase)

    return RexxClearMacroSpace();

    AROS_LIBFUNC_EXIT
}

/*
** This file was automatically generated by fdtrans 52.1.
** Do not edit it by hand. Instead, edit the sfd file
** that was used to generate this file
*/

#ifdef __USE_INLINE__
#undef __USE_INLINE__
#endif
#ifndef __NOGLOBALIFACE__
#define __NOGLOBALIFACE__
#endif

#include <exec/interfaces.h>
#include <exec/libraries.h>
#include <exec/emulation.h>
#include <interfaces/exec.h>
#include <interfaces/scalosfiletypeplugin.h>
#include <proto/scalosfiletypeplugin.h>


static inline int8  convert_int8 (uint32 x) { return x; }
static inline int16 convert_int16(uint32 x) { return x; }


STATIC struct Library * stub_OpenPPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct LibraryManagerInterface *Self = (struct LibraryManagerInterface *) ExtLib->ILibrary;

    return Self->Open(0);
}
STATIC CONST struct EmuTrap stub_Open = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_OpenPPC };

STATIC APTR stub_ClosePPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct LibraryManagerInterface *Self = (struct LibraryManagerInterface *) ExtLib->ILibrary;

    return Self->Close();
}
STATIC CONST struct EmuTrap stub_Close = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_ClosePPC };

STATIC APTR stub_ExpungePPC(ULONG *regarray __attribute__((unused)))
{
    return NULL;
}
STATIC CONST struct EmuTrap stub_Expunge = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_ExpungePPC };

STATIC ULONG stub_ReservedPPC(ULONG *regarray __attribute__((unused)))
{
    return 0UL;
}
STATIC CONST struct EmuTrap stub_Reserved = { TRAPINST, TRAPTYPE, stub_ReservedPPC };

static STRPTR stub_SCAToolTipInfoStringPPC(uint32 *regarray)
{
	struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((uint32)Base + Base->lib_PosSize);
	struct ScalosFileTypePluginIFace *Self = (struct ScalosFileTypePluginIFace *) ExtLib->MainIFace;

	return Self->SCAToolTipInfoString(
		(struct ScaToolTipInfoHookData *)regarray[8],
		(CONST_STRPTR)regarray[9]
	);
}
STATIC CONST struct EmuTrap stub_SCAToolTipInfoString = { TRAPINST, TRAPTYPE, (uint32 (*)(uint32 *))stub_SCAToolTipInfoStringPPC };

CONST CONST_APTR VecTable68K[] =
{
	&stub_Open,
	&stub_Close,
	&stub_Expunge,
	&stub_Reserved,
	&stub_SCAToolTipInfoString,
	(CONST_APTR)-1
};

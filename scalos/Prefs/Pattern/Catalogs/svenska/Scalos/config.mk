# $Date: 2009-02-17 21:22:13 +0200 (Di, 17 Feb 2009) $
# $Revision: 5 $
##############################################################################

ifndef $(TOPLEVEL)
	TOPLEVEL=$(shell pwd)/../../../../..
endif

###############################################################################

include $(TOPLEVEL)/config.mk
include $(TOPLEVEL)/rules.mk

###############################################################################
# Check compiler

ifeq ($(MACHINE), ppc-morphos)

###############################################################################
# MorphOS

LANG	=       svenska


else
ifeq ($(MACHINE), ppc-amigaos)

###############################################################################
# AmigOS4

LANG	=       swedish

else

###############################################################################
# AmigaOS and AROS

LANG	=       svenska

endif
endif

#include <exec/types.h>
#include "endianess.h"

struct M68k
{
  ULONG D[8]; // maintain this order of D before A for MOVEM!!! */
  ULONG A[8];
  ULONG PC;
  UWORD SR;

  ULONG oldvalue;
  ULONG lastresult;	// the result of the last operation
  ULONG subvalue;
  ULONG addvalue;
  ULONG lastop;		// the last operation
  ULONG instsize;
};

#define CPUFLAG_X 	0x10
#define CPUFLAG_N	0x08
#define CPUFLAG_Z	0x04
#define CPUFLAG_V	0x02
#define CPUFLAG_C	0x01

#define CPUFLAG_MASTER	(0x01 << 12)
#define CPUFLAG_USER	(0x01 << 13)

#define OP_SIZE_BYTE		0x00
#define OP_SIZE_WORD		0x01
#define OP_SIZE_LONG		0x02
#define OP_SIZE_MASK		0x03

#define OP_TYPE1		0x04 /* copy X, calculate N,Z, set V,C to zero */
#define OP_TYPE2		0x08 /* copy X,C calculate V,Z & N (add) */
#define OP_TYPE3		0x0c /* calculate X,V,C,Z & N */
#define OP_TYPE4		0x10 /* copy X,C calculate V,Z & N (sub) */
#define OP_TYPE5		0x14 /* copy X,  calculate V,C,Z,N (cmp) */
#define OP_TYPE6		0x18 /* unimplemented!!!!!! */
#define OP_TYPE_MASK		0x1c

#define OP_DONTCALCFLAGZ	0x20

#define OP_DONTCARE	0x00
#define OP_UPTODATE	OP_DONTCARE

#define OP_MOVE_BYTE	OP_TYPE1|OP_SIZE_BYTE
#define	OP_MOVE_WORD	OP_TYPE1|OP_SIZE_WORD
#define OP_MOVE_LONG	OP_TYPE1|OP_SIZE_LONG

#define OP_NOT_BYTE	OP_TYPE1|OP_SIZE_BYTE
#define OP_NOT_WORD	OP_TYPE1|OP_SIZE_WORD
#define OP_NOT_LONG	OP_TYPE1|OP_SIZE_LONG

#define OP_AND_BYTE	OP_TYPE1|OP_SIZE_BYTE
#define OP_AND_WORD	OP_TYPE1|OP_SIZE_WORD
#define OP_AND_LONG	OP_TYPE1|OP_SIZE_LONG

#define OP_EOR_BYTE	OP_TYPE1|OP_SIZE_BYTE
#define OP_EOR_WORD	OP_TYPE1|OP_SIZE_WORD
#define OP_EOR_LONG	OP_TYPE1|OP_SIZE_LONG

#define OP_OR_BYTE	OP_TYPE1|OP_SIZE_BYTE
#define OP_OR_WORD	OP_TYPE1|OP_SIZE_WORD
#define OP_OR_LONG	OP_TYPE1|OP_SIZE_LONG

#define OP_MULS_LONG	OP_TYPE1|OP_SIZE_LONG
#define OP_MULU_LONG	OP_TYPE1|OP_SIZE_LONG

/* correct the following!!! */
#define OP_DIVS_WORD	OP_TYPE1|OP_SIZE_LONG

#define OP_EXT		OP_TYPE1|OP_SIZE_LONG
#define OP_SWAP		OP_TYPE1|OP_SIZE_LONG

#define OP_ADD_BYTE	OP_TYPE2|OP_SIZE_BYTE
#define OP_ADD_WORD	OP_TYPE2|OP_SIZE_WORD
#define OP_ADD_LONG	OP_TYPE2|OP_SIZE_LONG

#define OP_NEG_BYTE	OP_TYPE3|OP_SIZE_BYTE
#define OP_NEG_WORD	OP_TYPE3|OP_SIZE_WORD
#define OP_NEG_LONG	OP_TYPE3|OP_SIZE_LONG

#define OP_NEGX_BYTE	OP_TYPE3|OP_SIZE_BYTE
#define OP_NEGX_WORD	OP_TYPE3|OP_SIZE_WORD
#define OP_NEGX_LONG	OP_TYPE3|OP_SIZE_LONG

#define OP_CMP_BYTE	OP_TYPE5|OP_SIZE_BYTE
#define OP_CMP_WORD	OP_TYPE5|OP_SIZE_WORD
#define OP_CMP_LONG	OP_TYPE5|OP_SIZE_LONG

#define OP_SUB_BYTE	OP_TYPE4|OP_SIZE_BYTE
#define OP_SUB_WORD	OP_TYPE4|OP_SIZE_WORD
#define OP_SUB_LONG	OP_TYPE4|OP_SIZE_LONG

#define OP_CMP_BYTE	OP_TYPE5|OP_SIZE_BYTE
#define OP_CMP_WORD	OP_TYPE5|OP_SIZE_WORD
#define OP_CMP_LONG	OP_TYPE5|OP_SIZE_LONG


#define OP_ASL_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_ASL_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_ASL_LONG	OP_TYPE6|OP_SIZE_LONG

#define OP_LSL_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_LSL_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_LSL_LONG	OP_TYPE6|OP_SIZE_LONG

#define OP_ROL_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_ROL_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_ROL_LONG	OP_TYPE6|OP_SIZE_LONG

#define OP_ROXL_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_ROXL_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_ROXL_LONG	OP_TYPE6|OP_SIZE_LONG

#define OP_ASR_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_ASR_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_ASR_LONG	OP_TYPE6|OP_SIZE_LONG

#define OP_LSR_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_LSR_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_LSR_LONG	OP_TYPE6|OP_SIZE_LONG

#define OP_ROR_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_ROR_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_ROR_LONG	OP_TYPE6|OP_SIZE_LONG

#define OP_ROXR_BYTE	OP_TYPE6|OP_SIZE_BYTE
#define OP_ROXR_WORD	OP_TYPE6|OP_SIZE_WORD
#define OP_ROXR_LONG	OP_TYPE6|OP_SIZE_LONG


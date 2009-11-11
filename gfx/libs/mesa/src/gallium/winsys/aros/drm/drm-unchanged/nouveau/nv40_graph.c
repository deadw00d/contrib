/*
 * Copyright (C) 2007 Ben Skeggs.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "drmP.h"
#include "drm.h"
#include "nouveau_drv.h"

/*TODO: deciper what each offset in the context represents. The below
 *      contexts are taken from dumps just after the 3D object is
 *      created.
 */
static void
nv40_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	/* Always has the "instance address" of itself at offset 0 */
	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	/* unknown */
	nv_wo32(dev, ctx, 0x00024/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00028/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00030/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0011c/4, 0x20010001);
	nv_wo32(dev, ctx, 0x00120/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00128/4, 0x02008821);
	nv_wo32(dev, ctx, 0x0016c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00170/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00174/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0017c/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00180/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00184/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00188/4, 0x80000000);
	nv_wo32(dev, ctx, 0x0018c/4, 0x80000000);
	nv_wo32(dev, ctx, 0x0019c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x001a0/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001b0/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001c0/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001d0/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x00340/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00350/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00354/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00358/4, 0x55555555);
	nv_wo32(dev, ctx, 0x0035c/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00388/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0039c/4, 0x00000010);
	nv_wo32(dev, ctx, 0x00480/4, 0x00000100);
	nv_wo32(dev, ctx, 0x00494/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00498/4, 0x00080060);
	nv_wo32(dev, ctx, 0x004b4/4, 0x00000080);
	nv_wo32(dev, ctx, 0x004b8/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x004bc/4, 0x00000001);
	nv_wo32(dev, ctx, 0x004d0/4, 0x46400000);
	nv_wo32(dev, ctx, 0x004ec/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x004f8/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x004fc/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00504/4, 0x00011100);
	for (i = 0x00520; i <= 0x0055c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00568/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x00594/4, 0x30201000);
	nv_wo32(dev, ctx, 0x00598/4, 0x70605040);
	nv_wo32(dev, ctx, 0x0059c/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x005a0/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x005b4/4, 0x40100000);
	nv_wo32(dev, ctx, 0x005cc/4, 0x00000004);
	nv_wo32(dev, ctx, 0x005d8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0060c/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x00610/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00614/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x00618/4, 0x00000098);
	nv_wo32(dev, ctx, 0x00628/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x0062c/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x00630/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00640/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x0067c/4, 0x00ffff00);
	/* 0x680-0x6BC - NV30_TCL_PRIMITIVE_3D_TX_ADDRESS_UNIT(0-15) */
	/* 0x6C0-0x6FC - NV30_TCL_PRIMITIVE_3D_TX_FORMAT_UNIT(0-15) */
	for (i = 0x006C0; i <= 0x006fc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	/* 0x700-0x73C - NV30_TCL_PRIMITIVE_3D_TX_WRAP_UNIT(0-15) */
	for (i = 0x00700; i <= 0x0073c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	/* 0x740-0x77C - NV30_TCL_PRIMITIVE_3D_TX_ENABLE_UNIT(0-15) */
	/* 0x780-0x7BC - NV30_TCL_PRIMITIVE_3D_TX_SWIZZLE_UNIT(0-15) */
	for (i = 0x00780; i <= 0x007bc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	/* 0x7C0-0x7FC - NV30_TCL_PRIMITIVE_3D_TX_FILTER_UNIT(0-15) */
	for (i = 0x007c0; i <= 0x007fc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	/* 0x800-0x83C - NV30_TCL_PRIMITIVE_3D_TX_XY_DIM_UNIT(0-15) */
	for (i = 0x00800; i <= 0x0083c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	/* 0x840-0x87C - NV30_TCL_PRIMITIVE_3D_TX_UNK07_UNIT(0-15) */
	/* 0x880-0x8BC - NV30_TCL_PRIMITIVE_3D_TX_DEPTH_UNIT(0-15) */
	for (i = 0x00880; i <= 0x008bc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	/* unknown */
	for (i = 0x00910; i <= 0x0091c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x00920; i <= 0x0092c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x00940; i <= 0x0094c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x00960; i <= 0x0096c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x00980/4, 0x00000002);
	nv_wo32(dev, ctx, 0x009b4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x009c0/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x009c4/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x009c8/4, 0x60103f00);
	nv_wo32(dev, ctx, 0x009d4/4, 0x00020000);
	nv_wo32(dev, ctx, 0x00a08/4, 0x00008100);
	nv_wo32(dev, ctx, 0x00aac/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00af0/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00af8/4, 0x80800001);
	nv_wo32(dev, ctx, 0x00bcc/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00bf8/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00bfc/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c00/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c04/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c08/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c0c/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c44/4, 0x00000001);
	for (i = 0x03008; i <= 0x03080; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x05288; i <= 0x08570; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x08628; i <= 0x08e18; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0bd28; i <= 0x0f010; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0f0c8; i <= 0x0f8b8; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x127c8; i <= 0x15ab0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x15b68; i <= 0x16358; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x19268; i <= 0x1c550; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x1c608; i <= 0x1cdf8; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x1fd08; i <= 0x22ff0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x230a8; i <= 0x23898; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x267a8; i <= 0x29a90; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x29b48; i <= 0x2a338; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

static void
nv41_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00000024/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00000028/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00000030/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0000011c/4, 0x20010001);
	nv_wo32(dev, ctx, 0x00000120/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00000128/4, 0x02008821);
	for (i = 0x00000178; i <= 0x00000180; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00000188/4, 0x00000040);
	for (i = 0x00000194; i <= 0x000001b0; i += 4)
		nv_wo32(dev, ctx, i/4, 0x80000000);
	nv_wo32(dev, ctx, 0x000001d0/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x00000340/4, 0x00040000);
	for (i = 0x00000350; i <= 0x0000035c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00000388/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0000039c/4, 0x00001010);
	nv_wo32(dev, ctx, 0x000003cc/4, 0x00000111);
	nv_wo32(dev, ctx, 0x000003d0/4, 0x00080060);
	nv_wo32(dev, ctx, 0x000003ec/4, 0x00000080);
	nv_wo32(dev, ctx, 0x000003f0/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x000003f4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00000408/4, 0x46400000);
	nv_wo32(dev, ctx, 0x00000418/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00000424/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00000428/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00000430/4, 0x00011100);
	for (i = 0x0000044c; i <= 0x00000488; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00000494/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x000004bc/4, 0x30201000);
	nv_wo32(dev, ctx, 0x000004c0/4, 0x70605040);
	nv_wo32(dev, ctx, 0x000004c4/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x000004c8/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x000004dc/4, 0x40100000);
	nv_wo32(dev, ctx, 0x000004f8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0000052c/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x00000530/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00000534/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x00000538/4, 0x00000098);
	nv_wo32(dev, ctx, 0x00000548/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x0000054c/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x00000550/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00000560/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x00000598/4, 0x00ffff00);
	for (i = 0x000005dc; i <= 0x00000618; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x0000061c; i <= 0x00000658; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x0000069c; i <= 0x000006d8; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x000006dc; i <= 0x00000718; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x0000071c; i <= 0x00000758; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x0000079c; i <= 0x000007d8; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x0000082c; i <= 0x00000838; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x0000083c; i <= 0x00000848; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x0000085c; i <= 0x00000868; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x0000087c; i <= 0x00000888; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x0000089c/4, 0x00000002);
	nv_wo32(dev, ctx, 0x000008d0/4, 0x00000021);
	nv_wo32(dev, ctx, 0x000008d4/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x000008e0/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x000008e4/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x000008e8/4, 0x20103f00);
	nv_wo32(dev, ctx, 0x000008f4/4, 0x00020000);
	nv_wo32(dev, ctx, 0x0000092c/4, 0x00008100);
	nv_wo32(dev, ctx, 0x000009b8/4, 0x00000001);
	nv_wo32(dev, ctx, 0x000009fc/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00000a04/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00000a08/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00000aac/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00000ab8/4, 0x0000ffff);
	for (i = 0x00000ad4; i <= 0x00000ae4; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00000ae8/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00000b20/4, 0x00000001);
	for (i = 0x00002ee8; i <= 0x00002f60; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x00005168; i <= 0x00007358; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x00007368; i <= 0x00007758; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0000a068; i <= 0x0000c258; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0000c268; i <= 0x0000c658; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0000ef68; i <= 0x00011158; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x00011168; i <= 0x00011558; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x00013e68; i <= 0x00016058; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x00016068; i <= 0x00016458; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
};

static void
nv43_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00024/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00028/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00030/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0011c/4, 0x20010001);
	nv_wo32(dev, ctx, 0x00120/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00128/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00178/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0017c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00180/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00188/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00194/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00198/4, 0x80000000);
	nv_wo32(dev, ctx, 0x0019c/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001a0/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001a4/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001a8/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001ac/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001b0/4, 0x80000000);
	nv_wo32(dev, ctx, 0x001d0/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x00340/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00350/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00354/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00358/4, 0x55555555);
	nv_wo32(dev, ctx, 0x0035c/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00388/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0039c/4, 0x00001010);
	nv_wo32(dev, ctx, 0x003cc/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003d0/4, 0x00080060);
	nv_wo32(dev, ctx, 0x003ec/4, 0x00000080);
	nv_wo32(dev, ctx, 0x003f0/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x003f4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00408/4, 0x46400000);
	nv_wo32(dev, ctx, 0x00418/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00424/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00428/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00430/4, 0x00011100);
	for (i = 0x0044c; i <= 0x00488; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00494/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x004bc/4, 0x30201000);
	nv_wo32(dev, ctx, 0x004c0/4, 0x70605040);
	nv_wo32(dev, ctx, 0x004c4/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x004c8/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x004dc/4, 0x40100000);
	nv_wo32(dev, ctx, 0x004f8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0052c/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x00530/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00534/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x00538/4, 0x00000098);
	nv_wo32(dev, ctx, 0x00548/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x0054c/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x00550/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00560/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x00598/4, 0x00ffff00);
	for (i = 0x005dc; i <= 0x00618; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x0061c; i <= 0x00658; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x0069c; i <= 0x006d8; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x006dc; i <= 0x00718; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x0071c; i <= 0x00758; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x0079c; i <= 0x007d8; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x0082c; i <= 0x00838; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x0083c; i <= 0x00848; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x0085c; i <= 0x00868; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x0087c; i <= 0x00888; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x0089c/4, 0x00000002);
	nv_wo32(dev, ctx, 0x008d0/4, 0x00000021);
	nv_wo32(dev, ctx, 0x008d4/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x008e0/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x008e4/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x008e8/4, 0x0c103f00);
	nv_wo32(dev, ctx, 0x008f4/4, 0x00020000);
	nv_wo32(dev, ctx, 0x0092c/4, 0x00008100);
	nv_wo32(dev, ctx, 0x009b8/4, 0x00000001);
	nv_wo32(dev, ctx, 0x009fc/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00a04/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00a08/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00a8c/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00a98/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00ab4/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00ab8/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00abc/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00ac0/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00af8/4, 0x00000001);
	for (i = 0x02ec0; i <= 0x02f38; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x04c80; i <= 0x06e70; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x06e80; i <= 0x07270; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x096c0; i <= 0x0b8b0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0b8c0; i <= 0x0bcb0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0e100; i <= 0x102f0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x10300; i <= 0x106f0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
};

static void
nv46_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00040/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00044/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0004c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00138/4, 0x20010001);
	nv_wo32(dev, ctx, 0x0013c/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00144/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00174/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00178/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0017c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00180/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00184/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00188/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0018c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00190/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00194/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00198/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0019c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x001a4/4, 0x00000040);
	nv_wo32(dev, ctx, 0x001ec/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x0035c/4, 0x00040000);
	nv_wo32(dev, ctx, 0x0036c/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00370/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00374/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00378/4, 0x55555555);
	nv_wo32(dev, ctx, 0x003a4/4, 0x00000008);
	nv_wo32(dev, ctx, 0x003b8/4, 0x00003010);
	nv_wo32(dev, ctx, 0x003dc/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003e0/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003e4/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003e8/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003ec/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003f0/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003f4/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003f8/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003fc/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00400/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00404/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00408/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0040c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00410/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00414/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00418/4, 0x00000111);
	nv_wo32(dev, ctx, 0x004b0/4, 0x00000111);
	nv_wo32(dev, ctx, 0x004b4/4, 0x00080060);
	nv_wo32(dev, ctx, 0x004d0/4, 0x00000080);
	nv_wo32(dev, ctx, 0x004d4/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x004d8/4, 0x00000001);
	nv_wo32(dev, ctx, 0x004ec/4, 0x46400000);
	nv_wo32(dev, ctx, 0x004fc/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00500/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00504/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00508/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0050c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00510/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00514/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00518/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0051c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00520/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00524/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00528/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0052c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00530/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00534/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00538/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0053c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00550/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00554/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x0055c/4, 0x00011100);
	for (i = 0x00578; i < 0x005b4; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005c0/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x005e8/4, 0x30201000);
	nv_wo32(dev, ctx, 0x005ec/4, 0x70605040);
	nv_wo32(dev, ctx, 0x005f0/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x005f4/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x00608/4, 0x40100000);
	nv_wo32(dev, ctx, 0x00624/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00658/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x0065c/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00660/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x00664/4, 0x00000098);
	nv_wo32(dev, ctx, 0x00674/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00678/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x0067c/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0068c/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x006c8/4, 0x00ffff00);
	for (i = 0x0070c; i <= 0x00748; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x0074c; i <= 0x00788; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x007cc; i <= 0x00808; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x0080c; i <= 0x00848; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x0084c; i <= 0x00888; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x008cc; i <= 0x00908; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x0095c; i <= 0x00968; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x0096c; i <= 0x00978; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x0098c; i <= 0x00998; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x009ac; i <= 0x009b8; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x009cc/4, 0x00000002);
	nv_wo32(dev, ctx, 0x00a00/4, 0x00000421);
	nv_wo32(dev, ctx, 0x00a04/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x00a08/4, 0x00011001);
	nv_wo32(dev, ctx, 0x00a14/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x00a18/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x00a1c/4, 0x0c103f00);
	nv_wo32(dev, ctx, 0x00a28/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00a60/4, 0x00008100);
	nv_wo32(dev, ctx, 0x00aec/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00b30/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00b38/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00b3c/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00bc0/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00bcc/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00be8/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00bec/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00bf0/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00bf4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00c2c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00c30/4, 0x08e00001);
	nv_wo32(dev, ctx, 0x00c34/4, 0x000e3000);
	for (i = 0x017f8; i <= 0x01870; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x035b8; i <= 0x057a8; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x057b8; i <= 0x05ba8; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x07f38; i <= 0x0a128; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0a138; i <= 0x0a528; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0c8b8; i <= 0x0eaa8; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0eab8; i <= 0x0eea8; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

/* This may only work on 7800 AGP cards, will include a warning */
static void
nv47_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00000024/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00000028/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00000030/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0000011c/4, 0x20010001);
	nv_wo32(dev, ctx, 0x00000120/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00000128/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00000178/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0000017c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00000180/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00000188/4, 0x00000040);
	for (i = 0x00000194; i <= 0x000001b0; i += 4)
		nv_wo32(dev, ctx, i/4, 0x80000000);
	nv_wo32(dev, ctx, 0x000001d0/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x00000340/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00000350/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00000354/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00000358/4, 0x55555555);
	nv_wo32(dev, ctx, 0x0000035c/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00000388/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0000039c/4, 0x00001010);
	for (i = 0x000003c0; i <= 0x000003fc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00000454/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00000458/4, 0x00080060);
	nv_wo32(dev, ctx, 0x00000474/4, 0x00000080);
	nv_wo32(dev, ctx, 0x00000478/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x0000047c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00000490/4, 0x46400000);
	nv_wo32(dev, ctx, 0x000004a0/4, 0xffff0000);
	for (i = 0x000004a4; i <= 0x000004e0; i += 4)
		nv_wo32(dev, ctx, i/4, 0x88888888);
	nv_wo32(dev, ctx, 0x000004f4/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x000004f8/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00000500/4, 0x00011100);
	for (i = 0x0000051c; i <= 0x00000558; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00000564/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x0000058c/4, 0x30201000);
	nv_wo32(dev, ctx, 0x00000590/4, 0x70605040);
	nv_wo32(dev, ctx, 0x00000594/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x00000598/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x000005ac/4, 0x40100000);
	nv_wo32(dev, ctx, 0x000005c8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x000005fc/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x00000600/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00000604/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x00000608/4, 0x00000098);
	nv_wo32(dev, ctx, 0x00000618/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x0000061c/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x00000620/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00000630/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x0000066c/4, 0x00ffff00);
	for (i = 0x000006b0; i <= 0x000006ec; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x000006f0; i <= 0x0000072c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x00000770; i <= 0x000007ac; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x000007b0; i <= 0x000007ec; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x000007f0; i <= 0x0000082c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x00000870; i <= 0x000008ac; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	nv_wo32(dev, ctx, 0x00000900/4, 0x0001bc80);
	nv_wo32(dev, ctx, 0x00000904/4, 0x0001bc80);
	nv_wo32(dev, ctx, 0x00000908/4, 0x0001bc80);
	nv_wo32(dev, ctx, 0x0000090c/4, 0x0001bc80);
	nv_wo32(dev, ctx, 0x00000910/4, 0x00000202);
	nv_wo32(dev, ctx, 0x00000914/4, 0x00000202);
	nv_wo32(dev, ctx, 0x00000918/4, 0x00000202);
	nv_wo32(dev, ctx, 0x0000091c/4, 0x00000202);
	for (i = 0x00000930; i <= 0x0000095c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	nv_wo32(dev, ctx, 0x00000970/4, 0x00000002);
	nv_wo32(dev, ctx, 0x000009a4/4, 0x00000021);
	nv_wo32(dev, ctx, 0x000009a8/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x000009b4/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x000009b8/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x000009bc/4, 0x40103f00);
	nv_wo32(dev, ctx, 0x000009c8/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00000a00/4, 0x00008100);
	nv_wo32(dev, ctx, 0x00000a8c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00000ad0/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00000adc/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00000ae0/4, 0x00888001);
	for (i = 0x00000b10; i <= 0x00000b8c; i += 4)
		nv_wo32(dev, ctx, i/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00000bb4/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00000bc0/4, 0x0000ffff);
	for (i = 0x00000bdc; i <= 0x00000bf8; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00000bfc/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00000c34/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00000c38/4, 0x08e00001);
	nv_wo32(dev, ctx, 0x00000c3c/4, 0x000e3000);
	for (i = 0x00003000; i <= 0x00003078; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x00004dc0; i <= 0x00006fb0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x00006fc0; i <= 0x000073b0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x00009800; i <= 0x0000b9f0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0000ba00; i <= 0x00010430; i += 24)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x00010440; i <= 0x00010830; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x00012c80; i <= 0x00014e70; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x00014e80; i <= 0x00015270; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x000176c0; i <= 0x000198b0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x000198c0; i <= 0x00019cb0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0001c100; i <= 0x0001e2f0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0001e300; i <= 0x0001e6f0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

static void
nv49_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00004/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00008/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x0000c/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00010/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00014/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00018/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x0001c/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00020/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x000c4/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x000c8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x000d0/4, 0x00000001);
	nv_wo32(dev, ctx, 0x001bc/4, 0x20010001);
	nv_wo32(dev, ctx, 0x001c0/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x001c8/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00218/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0021c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00220/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00228/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00234/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00238/4, 0x80000000);
	nv_wo32(dev, ctx, 0x0023c/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00240/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00244/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00248/4, 0x80000000);
	nv_wo32(dev, ctx, 0x0024c/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00250/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00270/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x003e0/4, 0x00040000);
	nv_wo32(dev, ctx, 0x003f0/4, 0x55555555);
	nv_wo32(dev, ctx, 0x003f4/4, 0x55555555);
	nv_wo32(dev, ctx, 0x003f8/4, 0x55555555);
	nv_wo32(dev, ctx, 0x003fc/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00428/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0043c/4, 0x00001010);
	nv_wo32(dev, ctx, 0x00460/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00464/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00468/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0046c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00470/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00474/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00478/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0047c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00480/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00484/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00488/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0048c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00490/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00494/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00498/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0049c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x004f4/4, 0x00000111);
	nv_wo32(dev, ctx, 0x004f8/4, 0x00080060);
	nv_wo32(dev, ctx, 0x00514/4, 0x00000080);
	nv_wo32(dev, ctx, 0x00518/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x0051c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00530/4, 0x46400000);
	nv_wo32(dev, ctx, 0x00540/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00544/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00548/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0054c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00550/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00554/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00558/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0055c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00560/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00564/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00568/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0056c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00570/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00574/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00578/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0057c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00580/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00594/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00598/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x005a0/4, 0x00011100);
	nv_wo32(dev, ctx, 0x005bc/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005c0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005c4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005c8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005cc/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005d0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005d4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005d8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005dc/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005e0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005e4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005e8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005ec/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005f0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005f4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005f8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00604/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x0062c/4, 0x30201000);
	nv_wo32(dev, ctx, 0x00630/4, 0x70605040);
	nv_wo32(dev, ctx, 0x00634/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x00638/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x0064c/4, 0x40100000);
	nv_wo32(dev, ctx, 0x00668/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0069c/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x006a0/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x006a4/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x006a8/4, 0x00000098);
	nv_wo32(dev, ctx, 0x006b8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x006bc/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x006c0/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x006d0/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x0070c/4, 0x00ffff00);
	for (i = 0x00750; i <= 0x0078c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x00790; i <= 0x007cc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x00810; i <= 0x0084c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x00850; i <= 0x0088c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x00890; i <= 0x008cc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x00910; i <= 0x0094c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x009a0; i <= 0x009ac; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x009b0; i <= 0x009bc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x009d0; i <= 0x009dc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x009f0; i <= 0x009fc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x00a10/4, 0x00000002);
	nv_wo32(dev, ctx, 0x00a44/4, 0x00000421);
	nv_wo32(dev, ctx, 0x00a48/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x00a54/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x00a58/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x00a5c/4, 0x20103f00);
	nv_wo32(dev, ctx, 0x00a68/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00aa0/4, 0x00008100);
	nv_wo32(dev, ctx, 0x00b2c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00b70/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00b7c/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00b80/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00bb0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bb4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bb8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bbc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bc0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bc4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bc8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bcc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bd0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bd4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bd8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bdc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00be0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00be4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00be8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bec/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bf0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bf4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bf8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bfc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c00/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c04/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c08/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c0c/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c10/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c14/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c18/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c1c/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c20/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c24/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c28/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c2c/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c54/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00c60/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00c7c/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c80/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c84/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c88/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c8c/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c90/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c94/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c98/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c9c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00cd4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00cd8/4, 0x08e00001);
	nv_wo32(dev, ctx, 0x00cdc/4, 0x000e3000);
	for (i = 0x030a0; i <= 0x03118; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x098a0; i <= 0x0ba90; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0baa0; i <= 0x0be90; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0e2e0; i <= 0x0fff0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x10008; i <= 0x104d0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x104e0; i <= 0x108d0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x12d20; i <= 0x14f10; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x14f20; i <= 0x15310; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x17760; i <= 0x19950; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x19960; i <= 0x19d50; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x1c1a0; i <= 0x1e390; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x1e3a0; i <= 0x1e790; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x20be0; i <= 0x22dd0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x22de0; i <= 0x231d0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

static void
nv4a_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00024/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00028/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00030/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0011c/4, 0x20010001);
	nv_wo32(dev, ctx, 0x00120/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00128/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00158/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0015c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00160/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00164/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00168/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0016c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00170/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00174/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00178/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0017c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00180/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00188/4, 0x00000040);
	nv_wo32(dev, ctx, 0x001d0/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x00340/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00350/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00354/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00358/4, 0x55555555);
	nv_wo32(dev, ctx, 0x0035c/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00388/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0039c/4, 0x00003010);
	nv_wo32(dev, ctx, 0x003cc/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003d0/4, 0x00080060);
	nv_wo32(dev, ctx, 0x003ec/4, 0x00000080);
	nv_wo32(dev, ctx, 0x003f0/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x003f4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00408/4, 0x46400000);
	nv_wo32(dev, ctx, 0x00418/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00424/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00428/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00430/4, 0x00011100);
	for (i = 0x0044c; i <= 0x00488; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00494/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x004bc/4, 0x30201000);
	nv_wo32(dev, ctx, 0x004c0/4, 0x70605040);
	nv_wo32(dev, ctx, 0x004c4/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x004c8/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x004dc/4, 0x40100000);
	nv_wo32(dev, ctx, 0x004f8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0052c/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x00530/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00534/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x00538/4, 0x00000098);
	nv_wo32(dev, ctx, 0x00548/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x0054c/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x00550/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0055c/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x00594/4, 0x00ffff00);
	for (i = 0x005d8; i <= 0x00614; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x00618; i <= 0x00654; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x00698; i <= 0x006d4; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x006d8; i <= 0x00714; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x00718; i <= 0x00754; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x00798; i <= 0x007d4; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x00828; i <= 0x00834; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x00838; i <= 0x00844; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x00858; i <= 0x00864; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x00878; i <= 0x00884; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x00898/4, 0x00000002);
	nv_wo32(dev, ctx, 0x008cc/4, 0x00000021);
	nv_wo32(dev, ctx, 0x008d0/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x008d4/4, 0x00011001);
	nv_wo32(dev, ctx, 0x008e0/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x008e4/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x008e8/4, 0x0c103f00);
	nv_wo32(dev, ctx, 0x008f4/4, 0x00040000);
	nv_wo32(dev, ctx, 0x0092c/4, 0x00008100);
	nv_wo32(dev, ctx, 0x009b8/4, 0x00000001);
	nv_wo32(dev, ctx, 0x009fc/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00a04/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00a08/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00a8c/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00a98/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00ab4/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00ab8/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00abc/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00ac0/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00af8/4, 0x00000001);
	for (i = 0x016c0; i <= 0x01738; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x03840; i <= 0x05670; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x05680; i <= 0x05a70; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x07e00; i <= 0x09ff0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0a000; i <= 0x0a3f0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0c780; i <= 0x0e970; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0e980; i <= 0x0ed70; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

static void
nv4b_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00004/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00008/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x0000c/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00010/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00014/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00018/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x0001c/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x00020/4, 0x0000c040);
	nv_wo32(dev, ctx, 0x000c4/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x000c8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x000d0/4, 0x00000001);
	nv_wo32(dev, ctx, 0x001bc/4, 0x20010001);
	nv_wo32(dev, ctx, 0x001c0/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x001c8/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00218/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0021c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00220/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00228/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00234/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00238/4, 0x80000000);
	nv_wo32(dev, ctx, 0x0023c/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00240/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00244/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00248/4, 0x80000000);
	nv_wo32(dev, ctx, 0x0024c/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00250/4, 0x80000000);
	nv_wo32(dev, ctx, 0x00270/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x003e0/4, 0x00040000);
	nv_wo32(dev, ctx, 0x003f0/4, 0x55555555);
	nv_wo32(dev, ctx, 0x003f4/4, 0x55555555);
	nv_wo32(dev, ctx, 0x003f8/4, 0x55555555);
	nv_wo32(dev, ctx, 0x003fc/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00428/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0043c/4, 0x00001010);
	nv_wo32(dev, ctx, 0x00460/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00464/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00468/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0046c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00470/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00474/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00478/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0047c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00480/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00484/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00488/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0048c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00490/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00494/4, 0x00000111);
	nv_wo32(dev, ctx, 0x00498/4, 0x00000111);
	nv_wo32(dev, ctx, 0x0049c/4, 0x00000111);
	nv_wo32(dev, ctx, 0x004f4/4, 0x00000111);
	nv_wo32(dev, ctx, 0x004f8/4, 0x00080060);
	nv_wo32(dev, ctx, 0x00514/4, 0x00000080);
	nv_wo32(dev, ctx, 0x00518/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x0051c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00530/4, 0x46400000);
	nv_wo32(dev, ctx, 0x00540/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00544/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00548/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0054c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00550/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00554/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00558/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0055c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00560/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00564/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00568/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0056c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00570/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00574/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00578/4, 0x88888888);
	nv_wo32(dev, ctx, 0x0057c/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00580/4, 0x88888888);
	nv_wo32(dev, ctx, 0x00594/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00598/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x005a0/4, 0x00011100);
	nv_wo32(dev, ctx, 0x005bc/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005c0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005c4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005c8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005cc/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005d0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005d4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005d8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005dc/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005e0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005e4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005e8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005ec/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005f0/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005f4/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x005f8/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00604/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x0062c/4, 0x30201000);
	nv_wo32(dev, ctx, 0x00630/4, 0x70605040);
	nv_wo32(dev, ctx, 0x00634/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x00638/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x0064c/4, 0x40100000);
	nv_wo32(dev, ctx, 0x00668/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0069c/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x006a0/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x006a4/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x006a8/4, 0x00000098);
	nv_wo32(dev, ctx, 0x006b8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x006bc/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x006c0/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x006d0/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x0070c/4, 0x00ffff00);
	for (i = 0x00750; i <= 0x0078c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x00790; i <= 0x007cc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x00810; i <= 0x0084c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x00850; i <= 0x0088c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x00890; i <= 0x008cc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x00910; i <= 0x0094c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x009a0; i <= 0x009ac; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x009b0; i <= 0x009bc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x009d0; i <= 0x009dc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x009f0; i <= 0x009fc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x00a10/4, 0x00000002);
	nv_wo32(dev, ctx, 0x00a44/4, 0x00000421);
	nv_wo32(dev, ctx, 0x00a48/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x00a54/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x00a58/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x00a5c/4, 0x20103f00);
	nv_wo32(dev, ctx, 0x00a68/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00aa0/4, 0x00008100);
	nv_wo32(dev, ctx, 0x00b2c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00b70/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00b7c/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00b80/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00bb0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bb4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bb8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bbc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bc0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bc4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bc8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bcc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bd0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bd4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bd8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bdc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00be0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00be4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00be8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bec/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bf0/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bf4/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bf8/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00bfc/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c00/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c04/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c08/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c0c/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c10/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c14/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c18/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c1c/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c20/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c24/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c28/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c2c/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00c54/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00c60/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00c7c/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c80/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c84/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c88/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c8c/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c90/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c94/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c98/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00c9c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00cd4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00cd8/4, 0x08e00001);
	nv_wo32(dev, ctx, 0x00cdc/4, 0x000e3000);
	for (i = 0x030a0; i <= 0x03118; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x098a0; i <= 0x0ba90; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x0baa0; i <= 0x0be90; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x0e2e0; i <= 0x0fff0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x10008; i <= 0x104d0; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x104e0; i <= 0x108d0; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x12d20; i <= 0x14f10; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x14f20; i <= 0x15310; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x17760; i <= 0x19950; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x19960; i <= 0x19d50; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

static void
nv4c_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00024/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00028/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00030/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0011c/4, 0x20010001);
	nv_wo32(dev, ctx, 0x00120/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00128/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00158/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0015c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00160/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00164/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00168/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0016c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00170/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00174/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00178/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0017c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00180/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00188/4, 0x00000040);
	nv_wo32(dev, ctx, 0x001d0/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x00340/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00350/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00354/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00358/4, 0x55555555);
	nv_wo32(dev, ctx, 0x0035c/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00388/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0039c/4, 0x00001010);
	nv_wo32(dev, ctx, 0x003d0/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003d4/4, 0x00080060);
	nv_wo32(dev, ctx, 0x003f0/4, 0x00000080);
	nv_wo32(dev, ctx, 0x003f4/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x003f8/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0040c/4, 0x46400000);
	nv_wo32(dev, ctx, 0x0041c/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00428/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x0042c/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00434/4, 0x00011100);
	for (i = 0x00450; i < 0x0048c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00498/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x004c0/4, 0x30201000);
	nv_wo32(dev, ctx, 0x004c4/4, 0x70605040);
	nv_wo32(dev, ctx, 0x004c8/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x004cc/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x004e0/4, 0x40100000);
	nv_wo32(dev, ctx, 0x004fc/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00530/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x00534/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00538/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x0053c/4, 0x00000098);
	nv_wo32(dev, ctx, 0x0054c/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x00550/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x00554/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00564/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x0059c/4, 0x00ffff00);
	for (i = 0x005e0; i <= 0x0061c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x00620; i <= 0x0065c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x006a0; i <= 0x006dc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x006e0; i <= 0x0071c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x00720; i <= 0x0075c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x007a0; i <= 0x007dc; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x00830; i <= 0x0083c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x00840; i <= 0x0084c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x00860; i <= 0x0086c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x00880; i <= 0x0088c; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x008a0/4, 0x00000002);
	nv_wo32(dev, ctx, 0x008d4/4, 0x00000020);
	nv_wo32(dev, ctx, 0x008d8/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x008dc/4, 0x00011001);
	nv_wo32(dev, ctx, 0x008e8/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x008ec/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x008f0/4, 0x0c103f00);
	nv_wo32(dev, ctx, 0x008fc/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00934/4, 0x00008100);
	nv_wo32(dev, ctx, 0x009c0/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00a04/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00a0c/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00a10/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00a74/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00a80/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00a9c/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00aa0/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00ad8/4, 0x00000001);
	for (i = 0x016a0; i < 0x01718; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x03460; i < 0x05650; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x05660; i < 0x05a50; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

static void
nv4e_graph_context_init(struct drm_device *dev, struct nouveau_gpuobj *ctx)
{
	int i;

	nv_wo32(dev, ctx, 0x00000/4, ctx->im_pramin->start);
	nv_wo32(dev, ctx, 0x00024/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00028/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00030/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0011c/4, 0x20010001);
	nv_wo32(dev, ctx, 0x00120/4, 0x0f73ef00);
	nv_wo32(dev, ctx, 0x00128/4, 0x02008821);
	nv_wo32(dev, ctx, 0x00158/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0015c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00160/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00164/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00168/4, 0x00000001);
	nv_wo32(dev, ctx, 0x0016c/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00170/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00174/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00178/4, 0x00000040);
	nv_wo32(dev, ctx, 0x0017c/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00180/4, 0x00000040);
	nv_wo32(dev, ctx, 0x00188/4, 0x00000040);
	nv_wo32(dev, ctx, 0x001d0/4, 0x0b0b0b0c);
	nv_wo32(dev, ctx, 0x00340/4, 0x00040000);
	nv_wo32(dev, ctx, 0x00350/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00354/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00358/4, 0x55555555);
	nv_wo32(dev, ctx, 0x0035c/4, 0x55555555);
	nv_wo32(dev, ctx, 0x00388/4, 0x00000008);
	nv_wo32(dev, ctx, 0x0039c/4, 0x00001010);
	nv_wo32(dev, ctx, 0x003cc/4, 0x00000111);
	nv_wo32(dev, ctx, 0x003d0/4, 0x00080060);
	nv_wo32(dev, ctx, 0x003ec/4, 0x00000080);
	nv_wo32(dev, ctx, 0x003f0/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x003f4/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00408/4, 0x46400000);
	nv_wo32(dev, ctx, 0x00418/4, 0xffff0000);
	nv_wo32(dev, ctx, 0x00424/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00428/4, 0x0fff0000);
	nv_wo32(dev, ctx, 0x00430/4, 0x00011100);
	for (i = 0x0044c; i <= 0x00488; i += 4)
		nv_wo32(dev, ctx, i/4, 0x07ff0000);
	nv_wo32(dev, ctx, 0x00494/4, 0x4b7fffff);
	nv_wo32(dev, ctx, 0x004bc/4, 0x30201000);
	nv_wo32(dev, ctx, 0x004c0/4, 0x70605040);
	nv_wo32(dev, ctx, 0x004c4/4, 0xb8a89888);
	nv_wo32(dev, ctx, 0x004c8/4, 0xf8e8d8c8);
	nv_wo32(dev, ctx, 0x004dc/4, 0x40100000);
	nv_wo32(dev, ctx, 0x004f8/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0052c/4, 0x435185d6);
	nv_wo32(dev, ctx, 0x00530/4, 0x2155b699);
	nv_wo32(dev, ctx, 0x00534/4, 0xfedcba98);
	nv_wo32(dev, ctx, 0x00538/4, 0x00000098);
	nv_wo32(dev, ctx, 0x00548/4, 0xffffffff);
	nv_wo32(dev, ctx, 0x0054c/4, 0x00ff7000);
	nv_wo32(dev, ctx, 0x00550/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x0055c/4, 0x00ff0000);
	nv_wo32(dev, ctx, 0x00594/4, 0x00ffff00);
	for (i = 0x005d8; i <= 0x00614; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00018488);
	for (i = 0x00618; i <= 0x00654; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00028202);
	for (i = 0x00698; i <= 0x006d4; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0000aae4);
	for (i = 0x006d8; i <= 0x00714; i += 4)
		nv_wo32(dev, ctx, i/4, 0x01012000);
	for (i = 0x00718; i <= 0x00754; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	for (i = 0x00798; i <= 0x007d4; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00100008);
	for (i = 0x00828; i <= 0x00834; i += 4)
		nv_wo32(dev, ctx, i/4, 0x0001bc80);
	for (i = 0x00838; i <= 0x00844; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000202);
	for (i = 0x00858; i <= 0x00864; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00000008);
	for (i = 0x00878; i <= 0x00884; i += 4)
		nv_wo32(dev, ctx, i/4, 0x00080008);
	nv_wo32(dev, ctx, 0x00898/4, 0x00000002);
	nv_wo32(dev, ctx, 0x008cc/4, 0x00000020);
	nv_wo32(dev, ctx, 0x008d0/4, 0x030c30c3);
	nv_wo32(dev, ctx, 0x008d4/4, 0x00011001);
	nv_wo32(dev, ctx, 0x008e0/4, 0x3e020200);
	nv_wo32(dev, ctx, 0x008e4/4, 0x00ffffff);
	nv_wo32(dev, ctx, 0x008e8/4, 0x0c103f00);
	nv_wo32(dev, ctx, 0x008f4/4, 0x00040000);
	nv_wo32(dev, ctx, 0x0092c/4, 0x00008100);
	nv_wo32(dev, ctx, 0x009b8/4, 0x00000001);
	nv_wo32(dev, ctx, 0x009fc/4, 0x00001001);
	nv_wo32(dev, ctx, 0x00a04/4, 0x00000003);
	nv_wo32(dev, ctx, 0x00a08/4, 0x00888001);
	nv_wo32(dev, ctx, 0x00a6c/4, 0x00000005);
	nv_wo32(dev, ctx, 0x00a78/4, 0x0000ffff);
	nv_wo32(dev, ctx, 0x00a94/4, 0x00005555);
	nv_wo32(dev, ctx, 0x00a98/4, 0x00000001);
	nv_wo32(dev, ctx, 0x00aa4/4, 0x00000001);
	for (i = 0x01668; i <= 0x016e0; i += 8)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
	for (i = 0x03428; i <= 0x05618; i += 24)
		nv_wo32(dev, ctx, i/4, 0x00000001);
	for (i = 0x05628; i <= 0x05a18; i += 16)
		nv_wo32(dev, ctx, i/4, 0x3f800000);
}

struct nouveau_channel *
nv40_graph_channel(struct drm_device *dev)
{
	struct drm_nouveau_private *dev_priv = dev->dev_private;
	uint32_t inst;
	int i;

	inst = nv_rd32(dev, NV40_PGRAPH_CTXCTL_CUR);
	if (!(inst & NV40_PGRAPH_CTXCTL_CUR_LOADED))
		return NULL;
	inst = (inst & NV40_PGRAPH_CTXCTL_CUR_INSTANCE) << 4;

	for (i = 0; i < dev_priv->engine.fifo.channels; i++) {
		struct nouveau_channel *chan = dev_priv->fifos[i];

		if (chan && chan->ramin_grctx &&
		    chan->ramin_grctx->instance == inst)
			return chan;
	}

	return NULL;
}

int
nv40_graph_create_context(struct nouveau_channel *chan)
{
	struct drm_device *dev = chan->dev;
	struct drm_nouveau_private *dev_priv = dev->dev_private;
	void (*ctx_init)(struct drm_device *, struct nouveau_gpuobj *);
	int ret;

	/* These functions populate the graphics context with a whole heap
	 * of default state.  All these functions are very similar, with
	 * a minimal amount of chipset-specific changes.  However, as we're
	 * currently dependant on the context programs used by the NVIDIA
	 * binary driver these functions must match the layout expected by
	 * them.  Hopefully at some point this will all change.
	 */
	switch (dev_priv->chipset) {
	case 0x40:
		ctx_init = nv40_graph_context_init;
		break;
	case 0x41:
	case 0x42:
		ctx_init = nv41_graph_context_init;
		break;
	case 0x43:
		ctx_init = nv43_graph_context_init;
		break;
	case 0x46:
		ctx_init = nv46_graph_context_init;
		break;
	case 0x47:
		ctx_init = nv47_graph_context_init;
		break;
	case 0x49:
		ctx_init = nv49_graph_context_init;
		break;
	case 0x44:
	case 0x4a:
		ctx_init = nv4a_graph_context_init;
		break;
	case 0x4b:
		ctx_init = nv4b_graph_context_init;
		break;
	case 0x4c:
	case 0x67:
		ctx_init = nv4c_graph_context_init;
		break;
	case 0x4e:
		ctx_init = nv4e_graph_context_init;
		break;
	default:
		ctx_init = nv40_graph_context_init;
		break;
	}

	/* Allocate a 175KiB block of PRAMIN to store the context.  This
	 * is massive overkill for a lot of chipsets, but it should be safe
	 * until we're able to implement this properly (will happen at more
	 * or less the same time we're able to write our own context programs.
	 */
	ret = nouveau_gpuobj_new_ref(dev, chan, NULL, 0, 175*1024, 16,
					  NVOBJ_FLAG_ZERO_ALLOC,
					  &chan->ramin_grctx);
	if (ret)
		return ret;

	/* Initialise default context values */
	dev_priv->engine.instmem.prepare_access(dev, true);
	ctx_init(dev, chan->ramin_grctx->gpuobj);
	dev_priv->engine.instmem.finish_access(dev);

	return 0;
}

void
nv40_graph_destroy_context(struct nouveau_channel *chan)
{
	nouveau_gpuobj_ref_del(chan->dev, &chan->ramin_grctx);
}

static int
nv40_graph_transfer_context(struct drm_device *dev, uint32_t inst, int save)
{
	uint32_t old_cp, tv = 1000, tmp;
	int i;

	old_cp = nv_rd32(dev, NV20_PGRAPH_CHANNEL_CTX_POINTER);
	nv_wr32(dev, NV20_PGRAPH_CHANNEL_CTX_POINTER, inst);

	tmp  = nv_rd32(dev, NV40_PGRAPH_CTXCTL_0310);
	tmp |= save ? NV40_PGRAPH_CTXCTL_0310_XFER_SAVE :
		      NV40_PGRAPH_CTXCTL_0310_XFER_LOAD;
	nv_wr32(dev, NV40_PGRAPH_CTXCTL_0310, tmp);

	tmp  = nv_rd32(dev, NV40_PGRAPH_CTXCTL_0304);
	tmp |= NV40_PGRAPH_CTXCTL_0304_XFER_CTX;
	nv_wr32(dev, NV40_PGRAPH_CTXCTL_0304, tmp);

	nouveau_wait_for_idle(dev);

	for (i = 0; i < tv; i++) {
		if (nv_rd32(dev, NV40_PGRAPH_CTXCTL_030C) == 0)
			break;
	}

	nv_wr32(dev, NV20_PGRAPH_CHANNEL_CTX_POINTER, old_cp);

	if (i == tv) {
		uint32_t ucstat = nv_rd32(dev, NV40_PGRAPH_CTXCTL_UCODE_STAT);
		NV_ERROR(dev, "Failed: Instance=0x%08x Save=%d\n", inst, save);
		NV_ERROR(dev, "IP: 0x%02x, Opcode: 0x%08x\n",
			 ucstat >> NV40_PGRAPH_CTXCTL_UCODE_STAT_IP_SHIFT,
			 ucstat  & NV40_PGRAPH_CTXCTL_UCODE_STAT_OP_MASK);
		NV_ERROR(dev, "0x40030C = 0x%08x\n",
			 nv_rd32(dev, NV40_PGRAPH_CTXCTL_030C));
		return -EBUSY;
	}

	return 0;
}

/* Restore the context for a specific channel into PGRAPH */
int
nv40_graph_load_context(struct nouveau_channel *chan)
{
	struct drm_device *dev = chan->dev;
	uint32_t inst;
	int ret;

	if (!chan->ramin_grctx)
		return -EINVAL;
	inst = chan->ramin_grctx->instance >> 4;

	ret = nv40_graph_transfer_context(dev, inst, 0);
	if (ret)
		return ret;

	/* 0x40032C, no idea of it's exact function.  Could simply be a
	 * record of the currently active PGRAPH context.  It's currently
	 * unknown as to what bit 24 does.  The nv ddx has it set, so we will
	 * set it here too.
	 */
	nv_wr32(dev, NV20_PGRAPH_CHANNEL_CTX_POINTER, inst);
	nv_wr32(dev, NV40_PGRAPH_CTXCTL_CUR,
		 (inst & NV40_PGRAPH_CTXCTL_CUR_INSTANCE) |
		  NV40_PGRAPH_CTXCTL_CUR_LOADED);
	/* 0x32E0 records the instance address of the active FIFO's PGRAPH
	 * context.  If at any time this doesn't match 0x40032C, you will
	 * recieve PGRAPH_INTR_CONTEXT_SWITCH
	 */
	nv_wr32(dev, NV40_PFIFO_GRCTX_INSTANCE, inst);
	return 0;
}

int
nv40_graph_unload_context(struct drm_device *dev)
{
	uint32_t inst;
	int ret;

	inst = nv_rd32(dev, NV40_PGRAPH_CTXCTL_CUR);
	if (!(inst & NV40_PGRAPH_CTXCTL_CUR_LOADED))
		return 0;
	inst &= NV40_PGRAPH_CTXCTL_CUR_INSTANCE;

	ret = nv40_graph_transfer_context(dev, inst, 1);

	nv_wr32(dev, NV40_PGRAPH_CTXCTL_CUR, inst);
	return ret;
}

/* These blocks of "magic numbers" are actually a microcode that the GPU uses
 * to control how graphics contexts get saved and restored between PRAMIN
 * and PGRAPH during a context switch.  We're currently using values seen
 * in mmio-traces of the binary driver.
 */
static uint32_t nv40_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00408f65, 0x00409406,
	0x0040a268, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004014e6, 0x007000a0, 0x00401a84, 0x00700082, 0x00600001, 0x00500061,
	0x00600002, 0x00401b68, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00110205, 0x0011420a, 0x00114210, 0x00110216,
	0x0012421b, 0x00120270, 0x001242c0, 0x00200040, 0x00100280, 0x00128100,
	0x00128120, 0x00128143, 0x0011415f, 0x0010815c, 0x0010c140, 0x00104029,
	0x00110400, 0x00104d10, 0x00500060, 0x00403b87, 0x0060000d, 0x004076e6,
	0x002000f0, 0x0060000a, 0x00200045, 0x00100620, 0x00108668, 0x0011466b,
	0x00120682, 0x0011068b, 0x00168691, 0x0010c6ae, 0x001206b4, 0x0020002a,
	0x001006c4, 0x001246f0, 0x002000c0, 0x00100700, 0x0010c3d7, 0x001043e1,
	0x00500060, 0x00405600, 0x00405684, 0x00600003, 0x00500067, 0x00600008,
	0x00500060, 0x00700082, 0x0020026c, 0x0060000a, 0x00104800, 0x00104901,
	0x00120920, 0x00200035, 0x00100940, 0x00148a00, 0x00104a14, 0x00200038,
	0x00100b00, 0x00138d00, 0x00104e00, 0x0012d600, 0x00105c00, 0x00104f06,
	0x0020031a, 0x0060000a, 0x00300000, 0x00200680, 0x00406c00, 0x00200684,
	0x00800001, 0x00200b62, 0x0060000a, 0x0020a0b0, 0x0040728a, 0x00201b68,
	0x00800041, 0x00407684, 0x00203e60, 0x00800002, 0x00408700, 0x00600006,
	0x00700003, 0x004080e6, 0x00700080, 0x0020031a, 0x0060000a, 0x00200004,
	0x00800001, 0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x0040a284,
	0x00700002, 0x00600004, 0x0040a268, 0x00700000, 0x00200000, 0x0060000a,
	0x00106002, 0x00700080, 0x00400a84, 0x00700002, 0x00400a68, 0x00500060,
	0x00600007, 0x00409388, 0x0060000f, 0x00000000, 0x00500060, 0x00200000,
	0x0060000a, 0x00700000, 0x00106001, 0x00700083, 0x00910880, 0x00901ffe,
	0x00940400, 0x00200020, 0x0060000b, 0x00500069, 0x0060000c, 0x00401b68,
	0x0040a406, 0x0040a505, 0x00600009, 0x00700005, 0x00700006, 0x0060000e,
	~0
};

static uint32_t nv41_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00408f65, 0x00409306,
	0x0040a068, 0x0040198f, 0x00200001, 0x0060000a, 0x00700080, 0x00104042,
	0x00200001, 0x0060000a, 0x00700000, 0x001040c5, 0x00401826, 0x00401968,
	0x0060000d, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004020e6, 0x007000a0, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e,
	0x001242c0, 0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143,
	0x0011415f, 0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d10,
	0x001046ec, 0x00500060, 0x00404087, 0x0060000d, 0x004079e6, 0x002000f1,
	0x0060000a, 0x00148653, 0x00104668, 0x0010c66d, 0x00120682, 0x0011068b,
	0x00168691, 0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4, 0x001146c6,
	0x00200020, 0x001006cc, 0x001046ed, 0x001246f0, 0x002000c0, 0x00100700,
	0x0010c3d7, 0x001043e1, 0x00500060, 0x00200233, 0x0060000a, 0x00104800,
	0x00108901, 0x00124920, 0x0020001f, 0x00100940, 0x00140965, 0x00148a00,
	0x00108a14, 0x00200020, 0x00100b00, 0x00134b2c, 0x0010cd00, 0x0010cd04,
	0x00114d08, 0x00104d80, 0x00104e00, 0x0012d600, 0x00105c00, 0x00104f06,
	0x002002d2, 0x0060000a, 0x00300000, 0x00200680, 0x00407200, 0x00200684,
	0x00800001, 0x00200b1a, 0x0060000a, 0x00206380, 0x0040788a, 0x00201480,
	0x00800041, 0x00408900, 0x00600006, 0x004085e6, 0x00700080, 0x0020007a,
	0x0060000a, 0x00104280, 0x002002d2, 0x0060000a, 0x00200004, 0x00800001,
	0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x0040a068, 0x00700000,
	0x00200000, 0x0060000a, 0x00106002, 0x00700080, 0x00400a68, 0x00500060,
	0x00600007, 0x00409388, 0x0060000f, 0x00500060, 0x00200000, 0x0060000a,
	0x00700000, 0x00106001, 0x00910880, 0x00901ffe, 0x00940400, 0x00200020,
	0x0060000b, 0x00500069, 0x0060000c, 0x00402168, 0x0040a206, 0x0040a305,
	0x00600009, 0x00700005, 0x00700006, 0x0060000e, ~0
};

static uint32_t nv43_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00409565, 0x00409a06,
	0x0040a868, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004014e6, 0x007000a0, 0x00401a84, 0x00700082, 0x00600001, 0x00500061,
	0x00600002, 0x00401b68, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e,
	0x001242c0, 0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143,
	0x0011415f, 0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d10,
	0x001046ec, 0x00500060, 0x00403a87, 0x0060000d, 0x00407ce6, 0x002000f1,
	0x0060000a, 0x00148653, 0x00104668, 0x0010c66d, 0x00120682, 0x0011068b,
	0x00168691, 0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4, 0x001146c6,
	0x00200020, 0x001006cc, 0x001046ed, 0x001246f0, 0x002000c0, 0x00100700,
	0x0010c3d7, 0x001043e1, 0x00500060, 0x00405800, 0x00405884, 0x00600003,
	0x00500067, 0x00600008, 0x00500060, 0x00700082, 0x00200233, 0x0060000a,
	0x00104800, 0x00108901, 0x00124920, 0x0020001f, 0x00100940, 0x00140965,
	0x00148a00, 0x00108a14, 0x00160b00, 0x00134b2c, 0x0010cd00, 0x0010cd04,
	0x0010cd08, 0x00104d80, 0x00104e00, 0x0012d600, 0x00105c00, 0x00104f06,
	0x002002c8, 0x0060000a, 0x00300000, 0x00200680, 0x00407200, 0x00200684,
	0x00800001, 0x00200b10, 0x0060000a, 0x00203870, 0x0040788a, 0x00201350,
	0x00800041, 0x00407c84, 0x00201560, 0x00800002, 0x00408d00, 0x00600006,
	0x00700003, 0x004086e6, 0x00700080, 0x002002c8, 0x0060000a, 0x00200004,
	0x00800001, 0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x0040a884,
	0x00700002, 0x00600004, 0x0040a868, 0x00700000, 0x00200000, 0x0060000a,
	0x00106002, 0x00700080, 0x00400a84, 0x00700002, 0x00400a68, 0x00500060,
	0x00600007, 0x00409988, 0x0060000f, 0x00000000, 0x00500060, 0x00200000,
	0x0060000a, 0x00700000, 0x00106001, 0x00700083, 0x00910880, 0x00901ffe,
	0x00940400, 0x00200020, 0x0060000b, 0x00500069, 0x0060000c, 0x00401b68,
	0x0040aa06, 0x0040ab05, 0x00600009, 0x00700005, 0x00700006, 0x0060000e,
	~0
};

static uint32_t nv44_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00409a65, 0x00409f06,
	0x0040ac68, 0x0040248f, 0x00200001, 0x0060000a, 0x00700080, 0x00104042,
	0x001041c6, 0x00104040, 0x00200001, 0x0060000a, 0x00700000, 0x001040c5,
	0x00402320, 0x00402321, 0x00402322, 0x00402324, 0x00402326, 0x0040232b,
	0x001040c5, 0x00402328, 0x001040c5, 0x00402320, 0x00402468, 0x0060000d,
	0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080, 0x00402be6,
	0x007000a0, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d, 0x00110158,
	0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4, 0x001041c9,
	0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e, 0x001242c0,
	0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143, 0x0011415f,
	0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d10, 0x001046ec,
	0x00500060, 0x00404b87, 0x0060000d, 0x004084e6, 0x002000f1, 0x0060000a,
	0x00148653, 0x00104668, 0x0010c66d, 0x00120682, 0x0011068b, 0x00168691,
	0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4, 0x001146c6, 0x001646cc,
	0x001186e6, 0x001046ed, 0x001246f0, 0x002000c0, 0x00100700, 0x0010c3d7,
	0x001043e1, 0x00500060, 0x00200232, 0x0060000a, 0x00104800, 0x00108901,
	0x00104910, 0x00124920, 0x0020001f, 0x00100940, 0x00140965, 0x00148a00,
	0x00108a14, 0x00160b00, 0x00134b2c, 0x0010cd00, 0x0010cd04, 0x0010cd08,
	0x00104d80, 0x00104e00, 0x0012d600, 0x00105c00, 0x00104f06, 0x002002c8,
	0x0060000a, 0x00300000, 0x00200080, 0x00407d00, 0x00200084, 0x00800001,
	0x00200510, 0x0060000a, 0x002037e0, 0x0040838a, 0x00201320, 0x00800029,
	0x00409400, 0x00600006, 0x004090e6, 0x00700080, 0x0020007a, 0x0060000a,
	0x00104280, 0x002002c8, 0x0060000a, 0x00200004, 0x00800001, 0x00700000,
	0x00200000, 0x0060000a, 0x00106002, 0x0040ac68, 0x00700000, 0x00200000,
	0x0060000a, 0x00106002, 0x00700080, 0x00400a68, 0x00500060, 0x00600007,
	0x00409e88, 0x0060000f, 0x00000000, 0x00500060, 0x00200000, 0x0060000a,
	0x00700000, 0x00106001, 0x00910880, 0x00901ffe, 0x01940000, 0x00200020,
	0x0060000b, 0x00500069, 0x0060000c, 0x00402c68, 0x0040ae06, 0x0040af05,
	0x00600009, 0x00700005, 0x00700006, 0x0060000e, ~0
};

static uint32_t nv46_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00408f65, 0x00409306,
	0x0040a068, 0x0040198f, 0x00200001, 0x0060000a, 0x00700080, 0x00104042,
	0x00200001, 0x0060000a, 0x00700000, 0x001040c5, 0x00401826, 0x00401968,
	0x0060000d, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004020e6, 0x007000a0, 0x00500060, 0x00200008, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e,
	0x001242c0, 0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143,
	0x0011415f, 0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d10,
	0x00500060, 0x00403f87, 0x0060000d, 0x004079e6, 0x002000f7, 0x0060000a,
	0x00200045, 0x00100620, 0x00104668, 0x0017466d, 0x0011068b, 0x00168691,
	0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4, 0x001146c6, 0x00200022,
	0x001006cc, 0x001246f0, 0x002000c0, 0x00100700, 0x0010c3d7, 0x001043e1,
	0x00500060, 0x0020027f, 0x0060000a, 0x00104800, 0x00108901, 0x00104910,
	0x00124920, 0x0020001f, 0x00100940, 0x00140965, 0x00148a00, 0x00108a14,
	0x00160b00, 0x00134b2c, 0x0010cd00, 0x0010cd04, 0x0010cd08, 0x00104d80,
	0x00104e00, 0x0012d600, 0x00105c00, 0x00104f06, 0x00105406, 0x00105709,
	0x00200316, 0x0060000a, 0x00300000, 0x00200080, 0x00407200, 0x00200084,
	0x00800001, 0x0020055e, 0x0060000a, 0x002037e0, 0x0040788a, 0x00201320,
	0x00800029, 0x00408900, 0x00600006, 0x004085e6, 0x00700080, 0x00200081,
	0x0060000a, 0x00104280, 0x00200316, 0x0060000a, 0x00200004, 0x00800001,
	0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x0040a068, 0x00700000,
	0x00200000, 0x0060000a, 0x00106002, 0x00700080, 0x00400a68, 0x00500060,
	0x00600007, 0x00409388, 0x0060000f, 0x00500060, 0x00200000, 0x0060000a,
	0x00700000, 0x00106001, 0x00910880, 0x00901ffe, 0x01940000, 0x00200020,
	0x0060000b, 0x00500069, 0x0060000c, 0x00402168, 0x0040a206, 0x0040a305,
	0x00600009, 0x00700005, 0x00700006, 0x0060000e, ~0
};

static uint32_t nv47_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00409265, 0x00409606,
	0x0040a368, 0x0040198f, 0x00200001, 0x0060000a, 0x00700080, 0x00104042,
	0x00200001, 0x0060000a, 0x00700000, 0x001040c5, 0x00401826, 0x00401968,
	0x0060000d, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004020e6, 0x007000a0, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e,
	0x001242c0, 0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143,
	0x0011415f, 0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d12,
	0x00500060, 0x00403f87, 0x0060000d, 0x00407ce6, 0x002000f0, 0x0060000a,
	0x00200020, 0x00100620, 0x00154650, 0x00104668, 0x0017466d, 0x0011068b,
	0x00168691, 0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4, 0x001146c6,
	0x00200022, 0x001006cc, 0x001246f0, 0x002000c0, 0x00100700, 0x0010c3d7,
	0x001043e1, 0x00500060, 0x00200268, 0x0060000a, 0x00104800, 0x00108901,
	0x00124920, 0x0020001f, 0x00100940, 0x00140965, 0x00144a00, 0x00104a19,
	0x0010ca1c, 0x00110b00, 0x00200028, 0x00100b08, 0x00134c2e, 0x0010cd00,
	0x0010cd04, 0x00120d08, 0x00104d80, 0x00104e00, 0x0012d600, 0x00105c00,
	0x00104f06, 0x00105406, 0x00105709, 0x00200318, 0x0060000a, 0x00300000,
	0x00200680, 0x00407500, 0x00200684, 0x00800001, 0x00200b60, 0x0060000a,
	0x00209540, 0x00407b8a, 0x00201350, 0x00800041, 0x00408c00, 0x00600006,
	0x004088e6, 0x00700080, 0x0020007a, 0x0060000a, 0x00104280, 0x00200318,
	0x0060000a, 0x00200004, 0x00800001, 0x00700000, 0x00200000, 0x0060000a,
	0x00106002, 0x0040a368, 0x00700000, 0x00200000, 0x0060000a, 0x00106002,
	0x00700080, 0x00400a68, 0x00500060, 0x00600007, 0x00409688, 0x0060000f,
	0x00500060, 0x00200000, 0x0060000a, 0x00700000, 0x00106001, 0x0091a880,
	0x00901ffe, 0x10940000, 0x00200020, 0x0060000b, 0x00500069, 0x0060000c,
	0x00402168, 0x0040a506, 0x0040a605, 0x00600009, 0x00700005, 0x00700006,
	0x0060000e, ~0
};

/* this is used for nv49 and nv4b */
static uint32_t nv49_4b_ctxprog[] = {
	0x00400564, 0x00400505, 0x00408165, 0x00408206, 0x00409e68, 0x00200020,
	0x0060000a, 0x00700080, 0x00104042, 0x00200020, 0x0060000a, 0x00700000,
	0x001040c5, 0x00400f26, 0x00401068, 0x0060000d, 0x0070008f, 0x0070000e,
	0x00408d68, 0x004015e6, 0x007000a0, 0x00700080, 0x0040180f, 0x00700000,
	0x00200029, 0x0060000a, 0x0011814d, 0x00110158, 0x00105401, 0x0020003a,
	0x00100051, 0x001040c5, 0x0010c1c4, 0x001041c9, 0x0010c1dc, 0x00150210,
	0x0012c225, 0x00108238, 0x0010823e, 0x001242c0, 0x00200040, 0x00100280,
	0x00128100, 0x00128120, 0x00128143, 0x0011415f, 0x0010815c, 0x0010c140,
	0x00104029, 0x00110400, 0x00104d12, 0x00500060, 0x004071e6, 0x00200118,
	0x0060000a, 0x00200020, 0x00100620, 0x00154650, 0x00104668, 0x0017466d,
	0x0011068b, 0x00168691, 0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4,
	0x001146c6, 0x00200022, 0x001006cc, 0x001246f0, 0x002000c0, 0x00100700,
	0x0010c3d7, 0x001043e1, 0x00500060, 0x00200290, 0x0060000a, 0x00104800,
	0x00108901, 0x00124920, 0x0020001f, 0x00100940, 0x00140965, 0x00144a00,
	0x00104a19, 0x0010ca1c, 0x00110b00, 0x00200028, 0x00100b08, 0x00134c2e,
	0x0010cd00, 0x0010cd04, 0x00120d08, 0x00104d80, 0x00104e00, 0x0012d600,
	0x00105c00, 0x00104f06, 0x00105406, 0x00105709, 0x00200340, 0x0060000a,
	0x00300000, 0x00200680, 0x00406a0f, 0x00200684, 0x00800001, 0x00200b88,
	0x0060000a, 0x00209540, 0x0040708a, 0x00201350, 0x00800041, 0x00407c0f,
	0x00600006, 0x00407ce6, 0x00700080, 0x002000a2, 0x0060000a, 0x00104280,
	0x00200340, 0x0060000a, 0x00200004, 0x00800001, 0x0070008e, 0x00408d68,
	0x0040020f, 0x00600006, 0x00409e68, 0x00600007, 0x0070000f, 0x0070000e,
	0x00408d68, 0x0091a880, 0x00901ffe, 0x10940000, 0x00200020, 0x0060000b,
	0x00500069, 0x0060000c, 0x00401568, 0x00700000, 0x00200001, 0x0040910e,
	0x00200021, 0x0060000a, 0x00409b0d, 0x00104a40, 0x00104a50, 0x00104a60,
	0x00104a70, 0x00104a80, 0x00104a90, 0x00104aa0, 0x00104ab0, 0x00407e0e,
	0x0040130f, 0x00408568, 0x0040a006, 0x0040a105, 0x00600009, 0x00700005,
	0x00700006, 0x0060000e, ~0
};


static uint32_t nv4a_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00409965, 0x00409e06,
	0x0040ac68, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004014e6, 0x007000a0, 0x00401a84, 0x00700082, 0x00600001, 0x00500061,
	0x00600002, 0x00401b68, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e,
	0x001242c0, 0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143,
	0x0011415f, 0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d10,
	0x001046ec, 0x00500060, 0x00403a87, 0x0060000d, 0x00407de6, 0x002000f1,
	0x0060000a, 0x00148653, 0x00104668, 0x0010c66d, 0x00120682, 0x0011068b,
	0x00168691, 0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4, 0x001146c6,
	0x001646cc, 0x001186e6, 0x001046ed, 0x001246f0, 0x002000c0, 0x00100700,
	0x0010c3d7, 0x001043e1, 0x00500060, 0x00405800, 0x00405884, 0x00600003,
	0x00500067, 0x00600008, 0x00500060, 0x00700082, 0x00200232, 0x0060000a,
	0x00104800, 0x00108901, 0x00104910, 0x00124920, 0x0020001f, 0x00100940,
	0x00140965, 0x00148a00, 0x00108a14, 0x00160b00, 0x00134b2c, 0x0010cd00,
	0x0010cd04, 0x0010cd08, 0x00104d80, 0x00104e00, 0x0012d600, 0x00105c00,
	0x00104f06, 0x002002c8, 0x0060000a, 0x00300000, 0x00200080, 0x00407300,
	0x00200084, 0x00800001, 0x00200510, 0x0060000a, 0x002037e0, 0x0040798a,
	0x00201320, 0x00800029, 0x00407d84, 0x00201560, 0x00800002, 0x00409100,
	0x00600006, 0x00700003, 0x00408ae6, 0x00700080, 0x0020007a, 0x0060000a,
	0x00104280, 0x002002c8, 0x0060000a, 0x00200004, 0x00800001, 0x00700000,
	0x00200000, 0x0060000a, 0x00106002, 0x0040ac84, 0x00700002, 0x00600004,
	0x0040ac68, 0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x00700080,
	0x00400a84, 0x00700002, 0x00400a68, 0x00500060, 0x00600007, 0x00409d88,
	0x0060000f, 0x00000000, 0x00500060, 0x00200000, 0x0060000a, 0x00700000,
	0x00106001, 0x00700083, 0x00910880, 0x00901ffe, 0x01940000, 0x00200020,
	0x0060000b, 0x00500069, 0x0060000c, 0x00401b68, 0x0040ae06, 0x0040af05,
	0x00600009, 0x00700005, 0x00700006, 0x0060000e, ~0
};

static uint32_t nv4c_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00409065, 0x00409406,
	0x0040a168, 0x0040198f, 0x00200001, 0x0060000a, 0x00700080, 0x00104042,
	0x00200001, 0x0060000a, 0x00700000, 0x001040c5, 0x00401826, 0x00401968,
	0x0060000d, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004020e6, 0x007000a0, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e,
	0x001242c0, 0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143,
	0x0011415f, 0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d10,
	0x0010427e, 0x001046ec, 0x00500060, 0x00404187, 0x0060000d, 0x00407ae6,
	0x002000f2, 0x0060000a, 0x00148653, 0x00104668, 0x0010c66d, 0x00120682,
	0x0011068b, 0x00168691, 0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4,
	0x001146c6, 0x00200020, 0x001006cc, 0x001046ed, 0x001246f0, 0x002000c0,
	0x00100700, 0x0010c3d7, 0x001043e1, 0x00500060, 0x00200234, 0x0060000a,
	0x00104800, 0x00108901, 0x00104910, 0x00124920, 0x0020001f, 0x00100940,
	0x00140965, 0x00148a00, 0x00108a14, 0x00140b00, 0x00134b2c, 0x0010cd00,
	0x0010cd04, 0x00104d08, 0x00104d80, 0x00104e00, 0x0012d600, 0x00105c00,
	0x00104f06, 0x002002c0, 0x0060000a, 0x00300000, 0x00200080, 0x00407300,
	0x00200084, 0x00800001, 0x00200508, 0x0060000a, 0x00201320, 0x0040798a,
	0xfffffaf8, 0x00800029, 0x00408a00, 0x00600006, 0x004086e6, 0x00700080,
	0x0020007a, 0x0060000a, 0x00104280, 0x002002c0, 0x0060000a, 0x00200004,
	0x00800001, 0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x0040a168,
	0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x00700080, 0x00400a68,
	0x00500060, 0x00600007, 0x00409488, 0x0060000f, 0x00500060, 0x00200000,
	0x0060000a, 0x00700000, 0x00106001, 0x00910880, 0x00901ffe, 0x01940000,
	0x00200020, 0x0060000b, 0x00500069, 0x0060000c, 0x00402168, 0x0040a306,
	0x0040a405, 0x00600009, 0x00700005, 0x00700006, 0x0060000e, ~0
};

static uint32_t nv4e_ctxprog[] = {
	0x00400889, 0x00200000, 0x0060000a, 0x00200000, 0x00300000, 0x00800001,
	0x00700009, 0x0060000e, 0x00400d64, 0x00400d05, 0x00409565, 0x00409a06,
	0x0040a868, 0x00200000, 0x0060000a, 0x00700000, 0x00106000, 0x00700080,
	0x004014e6, 0x007000a0, 0x00401a84, 0x00700082, 0x00600001, 0x00500061,
	0x00600002, 0x00401b68, 0x00500060, 0x00200001, 0x0060000a, 0x0011814d,
	0x00110158, 0x00105401, 0x0020003a, 0x00100051, 0x001040c5, 0x0010c1c4,
	0x001041c9, 0x0010c1dc, 0x00150210, 0x0012c225, 0x00108238, 0x0010823e,
	0x001242c0, 0x00200040, 0x00100280, 0x00128100, 0x00128120, 0x00128143,
	0x0011415f, 0x0010815c, 0x0010c140, 0x00104029, 0x00110400, 0x00104d10,
	0x001046ec, 0x00500060, 0x00403a87, 0x0060000d, 0x00407ce6, 0x002000f1,
	0x0060000a, 0x00148653, 0x00104668, 0x0010c66d, 0x00120682, 0x0011068b,
	0x00168691, 0x001046ae, 0x001046b0, 0x001206b4, 0x001046c4, 0x001146c6,
	0x001646cc, 0x001186e6, 0x001046ed, 0x001246f0, 0x002000c0, 0x00100700,
	0x0010c3d7, 0x001043e1, 0x00500060, 0x00405800, 0x00405884, 0x00600003,
	0x00500067, 0x00600008, 0x00500060, 0x00700082, 0x00200232, 0x0060000a,
	0x00104800, 0x00108901, 0x00104910, 0x00124920, 0x0020001f, 0x00100940,
	0x00140965, 0x00148a00, 0x00108a14, 0x00140b00, 0x00134b2c, 0x0010cd00,
	0x0010cd04, 0x00104d08, 0x00104d80, 0x00104e00, 0x00105c00, 0x00104f06,
	0x002002b2, 0x0060000a, 0x00300000, 0x00200080, 0x00407200, 0x00200084,
	0x00800001, 0x002004fa, 0x0060000a, 0x00201320, 0x0040788a, 0xfffffb06,
	0x00800029, 0x00407c84, 0x00200b20, 0x00800002, 0x00408d00, 0x00600006,
	0x00700003, 0x004086e6, 0x00700080, 0x002002b2, 0x0060000a, 0x00200004,
	0x00800001, 0x00700000, 0x00200000, 0x0060000a, 0x00106002, 0x0040a884,
	0x00700002, 0x00600004, 0x0040a868, 0x00700000, 0x00200000, 0x0060000a,
	0x00106002, 0x00700080, 0x00400a84, 0x00700002, 0x00400a68, 0x00500060,
	0x00600007, 0x00409988, 0x0060000f, 0x00000000, 0x00500060, 0x00200000,
	0x0060000a, 0x00700000, 0x00106001, 0x00700083, 0x00910880, 0x00901ffe,
	0x01940000, 0x00200020, 0x0060000b, 0x00500069, 0x0060000c, 0x00401b68,
	0x0040aa06, 0x0040ab05, 0x00600009, 0x00700005, 0x00700006, 0x0060000e,
	~0
};

/*
 * G70		0x47
 * G71		0x49
 * NV45		0x48
 * G72[M]	0x46
 * G73		0x4b
 * C51_G7X	0x4c
 * C51		0x4e
 */
int
nv40_graph_init(struct drm_device *dev)
{
	struct drm_nouveau_private *dev_priv =
		(struct drm_nouveau_private *)dev->dev_private;
	uint32_t *ctxprog = NULL;
	uint32_t vramsz, tmp;
	int i, j;

	nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) &
			~NV_PMC_ENABLE_PGRAPH);
	nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) |
			 NV_PMC_ENABLE_PGRAPH);

	switch (dev_priv->chipset) {
	case 0x40:
		ctxprog = nv40_ctxprog;
		break;
	case 0x41:
	case 0x42:
		ctxprog = nv41_ctxprog;
		break;
	case 0x43:
		ctxprog = nv43_ctxprog;
		break;
	case 0x44:
		ctxprog = nv44_ctxprog;
		break;
	case 0x46:
		ctxprog = nv46_ctxprog;
		break;
	case 0x47:
		ctxprog = nv47_ctxprog;
		break;
	case 0x49:
		ctxprog = nv49_4b_ctxprog;
		break;
	case 0x4a:
		ctxprog = nv4a_ctxprog;
		break;
	case 0x4b:
		ctxprog = nv49_4b_ctxprog;
		break;
	case 0x4c:
	case 0x67:
		ctxprog = nv4c_ctxprog;
		break;
	case 0x4e:
		ctxprog = nv4e_ctxprog;
		break;
	default:
		NV_ERROR(dev, "Context program for 0x%02x unavailable\n",
			 dev_priv->chipset);
		dev_priv->engine.graph.accel_blocked = true;
		break;
	}

	/* Load the context program onto the card */
	if (ctxprog) {
		NV_DEBUG(dev, "Loading context program\n");

		i = 0;
		nv_wr32(dev, NV40_PGRAPH_CTXCTL_UCODE_INDEX, 0);
		while (ctxprog[i] != ~0) {
			nv_wr32(dev, NV40_PGRAPH_CTXCTL_UCODE_DATA, ctxprog[i]);
			i++;
		}
	}

	/* No context present currently */
	nv_wr32(dev, NV40_PGRAPH_CTXCTL_CUR, 0x00000000);

	nv_wr32(dev, NV03_PGRAPH_INTR   , 0xFFFFFFFF);
	nv_wr32(dev, NV40_PGRAPH_INTR_EN, 0xFFFFFFFF);

	nv_wr32(dev, NV04_PGRAPH_DEBUG_0, 0xFFFFFFFF);
	nv_wr32(dev, NV04_PGRAPH_DEBUG_0, 0x00000000);
	nv_wr32(dev, NV04_PGRAPH_DEBUG_1, 0x401287c0);
	nv_wr32(dev, NV04_PGRAPH_DEBUG_3, 0xe0de8055);
	nv_wr32(dev, NV10_PGRAPH_DEBUG_4, 0x00008000);
	nv_wr32(dev, NV04_PGRAPH_LIMIT_VIOL_PIX, 0x00be3c5f);

	nv_wr32(dev, NV10_PGRAPH_CTX_CONTROL, 0x10010100);
	nv_wr32(dev, NV10_PGRAPH_STATE      , 0xFFFFFFFF);

	j = nv_rd32(dev, 0x1540) & 0xff;
	if (j) {
		for (i = 0; !(j & 1); j >>= 1, i++)
			;
		nv_wr32(dev, 0x405000, i);
	}

	if (dev_priv->chipset == 0x40) {
		nv_wr32(dev, 0x4009b0, 0x83280fff);
		nv_wr32(dev, 0x4009b4, 0x000000a0);
	} else {
		nv_wr32(dev, 0x400820, 0x83280eff);
		nv_wr32(dev, 0x400824, 0x000000a0);
	}

	switch (dev_priv->chipset) {
	case 0x40:
	case 0x45:
		nv_wr32(dev, 0x4009b8, 0x0078e366);
		nv_wr32(dev, 0x4009bc, 0x0000014c);
		break;
	case 0x41:
	case 0x42: /* pciid also 0x00Cx */
	/* case 0x0120: XXX (pciid) */
		nv_wr32(dev, 0x400828, 0x007596ff);
		nv_wr32(dev, 0x40082c, 0x00000108);
		break;
	case 0x43:
		nv_wr32(dev, 0x400828, 0x0072cb77);
		nv_wr32(dev, 0x40082c, 0x00000108);
		break;
	case 0x44:
	case 0x46: /* G72 */
	case 0x4a:
	case 0x4c: /* G7x-based C51 */
	case 0x4e:
		nv_wr32(dev, 0x400860, 0);
		nv_wr32(dev, 0x400864, 0);
		break;
	case 0x47: /* G70 */
	case 0x49: /* G71 */
	case 0x4b: /* G73 */
		nv_wr32(dev, 0x400828, 0x07830610);
		nv_wr32(dev, 0x40082c, 0x0000016A);
		break;
	default:
		break;
	}

	nv_wr32(dev, 0x400b38, 0x2ffff800);
	nv_wr32(dev, 0x400b3c, 0x00006000);

	/* copy tile info from PFB */
	switch (dev_priv->chipset) {
	case 0x40: /* vanilla NV40 */
		for (i = 0; i < NV10_PFB_TILE__SIZE; i++) {
			tmp = nv_rd32(dev, NV10_PFB_TILE(i));
			nv_wr32(dev, NV40_PGRAPH_TILE0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TILE1(i), tmp);
			tmp = nv_rd32(dev, NV10_PFB_TLIMIT(i));
			nv_wr32(dev, NV40_PGRAPH_TLIMIT0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TLIMIT1(i), tmp);
			tmp = nv_rd32(dev, NV10_PFB_TSIZE(i));
			nv_wr32(dev, NV40_PGRAPH_TSIZE0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TSIZE1(i), tmp);
			tmp = nv_rd32(dev, NV10_PFB_TSTATUS(i));
			nv_wr32(dev, NV40_PGRAPH_TSTATUS0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TSTATUS1(i), tmp);
		}
		break;
	case 0x44:
	case 0x4a:
	case 0x4e: /* NV44-based cores don't have 0x406900? */
		for (i = 0; i < NV40_PFB_TILE__SIZE_0; i++) {
			tmp = nv_rd32(dev, NV40_PFB_TILE(i));
			nv_wr32(dev, NV40_PGRAPH_TILE0(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TLIMIT(i));
			nv_wr32(dev, NV40_PGRAPH_TLIMIT0(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TSIZE(i));
			nv_wr32(dev, NV40_PGRAPH_TSIZE0(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TSTATUS(i));
			nv_wr32(dev, NV40_PGRAPH_TSTATUS0(i), tmp);
		}
		break;
	case 0x46:
	case 0x47:
	case 0x49:
	case 0x4b: /* G7X-based cores */
		for (i = 0; i < NV40_PFB_TILE__SIZE_1; i++) {
			tmp = nv_rd32(dev, NV40_PFB_TILE(i));
			nv_wr32(dev, NV47_PGRAPH_TILE0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TILE1(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TLIMIT(i));
			nv_wr32(dev, NV47_PGRAPH_TLIMIT0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TLIMIT1(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TSIZE(i));
			nv_wr32(dev, NV47_PGRAPH_TSIZE0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TSIZE1(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TSTATUS(i));
			nv_wr32(dev, NV47_PGRAPH_TSTATUS0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TSTATUS1(i), tmp);
		}
		break;
	default: /* everything else */
		for (i = 0; i < NV40_PFB_TILE__SIZE_0; i++) {
			tmp = nv_rd32(dev, NV40_PFB_TILE(i));
			nv_wr32(dev, NV40_PGRAPH_TILE0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TILE1(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TLIMIT(i));
			nv_wr32(dev, NV40_PGRAPH_TLIMIT0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TLIMIT1(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TSIZE(i));
			nv_wr32(dev, NV40_PGRAPH_TSIZE0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TSIZE1(i), tmp);
			tmp = nv_rd32(dev, NV40_PFB_TSTATUS(i));
			nv_wr32(dev, NV40_PGRAPH_TSTATUS0(i), tmp);
			nv_wr32(dev, NV40_PGRAPH_TSTATUS1(i), tmp);
		}
		break;
	}

	/* begin RAM config */
	vramsz = drm_get_resource_len(dev, 0) - 1;
	switch (dev_priv->chipset) {
	case 0x40:
		nv_wr32(dev, 0x4009A4, nv_rd32(dev, NV04_PFB_CFG0));
		nv_wr32(dev, 0x4009A8, nv_rd32(dev, NV04_PFB_CFG1));
		nv_wr32(dev, 0x4069A4, nv_rd32(dev, NV04_PFB_CFG0));
		nv_wr32(dev, 0x4069A8, nv_rd32(dev, NV04_PFB_CFG1));
		nv_wr32(dev, 0x400820, 0);
		nv_wr32(dev, 0x400824, 0);
		nv_wr32(dev, 0x400864, vramsz);
		nv_wr32(dev, 0x400868, vramsz);
		break;
	default:
		switch (dev_priv->chipset) {
		case 0x46:
		case 0x47:
		case 0x49:
		case 0x4b:
			nv_wr32(dev, 0x400DF0, nv_rd32(dev, NV04_PFB_CFG0));
			nv_wr32(dev, 0x400DF4, nv_rd32(dev, NV04_PFB_CFG1));
			break;
		default:
			nv_wr32(dev, 0x4009F0, nv_rd32(dev, NV04_PFB_CFG0));
			nv_wr32(dev, 0x4009F4, nv_rd32(dev, NV04_PFB_CFG1));
			break;
		}
		nv_wr32(dev, 0x4069F0, nv_rd32(dev, NV04_PFB_CFG0));
		nv_wr32(dev, 0x4069F4, nv_rd32(dev, NV04_PFB_CFG1));
		nv_wr32(dev, 0x400840, 0);
		nv_wr32(dev, 0x400844, 0);
		nv_wr32(dev, 0x4008A0, vramsz);
		nv_wr32(dev, 0x4008A4, vramsz);
		break;
	}

	return 0;
}

void nv40_graph_takedown(struct drm_device *dev)
{
}

struct nouveau_pgraph_object_class nv40_graph_grclass[] = {
	{ 0x0030, false, NULL }, /* null */
	{ 0x0039, false, NULL }, /* m2mf */
	{ 0x004a, false, NULL }, /* gdirect */
	{ 0x009f, false, NULL }, /* imageblit (nv12) */
	{ 0x008a, false, NULL }, /* ifc */
	{ 0x0089, false, NULL }, /* sifm */
	{ 0x3089, false, NULL }, /* sifm (nv40) */
	{ 0x0062, false, NULL }, /* surf2d */
	{ 0x0043, false, NULL }, /* rop */
	{ 0x0012, false, NULL }, /* beta1 */
	{ 0x0072, false, NULL }, /* beta4 */
	{ 0x0019, false, NULL }, /* cliprect */
	{ 0x0044, false, NULL }, /* pattern */
	{ 0x309e, false, NULL }, /* swzsurf */
	{ 0x4097, false, NULL }, /* curie (nv40) */
	{ 0x4497, false, NULL }, /* curie (nv44) */
	{}
};


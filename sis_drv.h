/* sis_drv.h -- Private header for sis driver -*- linux-c -*- */
/*
 * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.
 * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _SIS_DRV_H_
#define _SIS_DRV_H_

/* General customization:
 */

#define DRIVER_AUTHOR		"SIS, Tungsten Graphics"
#define DRIVER_NAME		"sis"
#define DRIVER_DESC		"SIS 300/630/540"
#define DRIVER_DATE		"20060619"
#define DRIVER_MAJOR		1
#define DRIVER_MINOR		2
#define DRIVER_PATCHLEVEL	1

enum sis_family {
	SIS_OTHER = 0,
	SIS_CHIP_315 = 1,
};

#if defined(__linux__)
#define SIS_HAVE_CORE_MM
#endif

#ifdef SIS_HAVE_CORE_MM
#include "drm_sman.h"

#define SIS_BASE (dev_priv->mmio)
#define SIS_READ(reg)	 DRM_READ32(SIS_BASE, reg);
#define SIS_WRITE(reg, val)   DRM_WRITE32(SIS_BASE, reg, val);

typedef struct drm_sis_private {
	drm_local_map_t *mmio;
	unsigned int idle_fault;
	drm_sman_t sman;
	unsigned int chipset;
	int vram_initialized;
	int agp_initialized;
	unsigned long vram_offset;
	unsigned long agp_offset;
} drm_sis_private_t;

extern int sis_idle(drm_device_t *dev);
extern void sis_reclaim_buffers_locked(drm_device_t *dev, struct file *filp);
extern void sis_lastclose(drm_device_t *dev);

#else
#include "sis_ds.h"

typedef struct drm_sis_private {
	memHeap_t *AGPHeap;
	memHeap_t *FBHeap;
} drm_sis_private_t;

extern int sis_init_context(drm_device_t * dev, int context);
extern int sis_final_context(drm_device_t * dev, int context);

#endif



extern drm_ioctl_desc_t sis_ioctls[];
extern int sis_max_ioctl;

#endif

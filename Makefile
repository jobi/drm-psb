obj-m += drm_psb.o
obj-m += psb.o

drm_psb-objs := drm_auth.o drm_bufs.o drm_context.o drm_dma.o drm_drawable.o \
		drm_drv.o drm_fops.o drm_ioctl.o drm_irq.o \
		drm_lock.o drm_memory.o drm_proc.o drm_stub.o drm_vm.o \
		drm_sysfs.o drm_pci.o drm_agpsupport.o drm_scatter.o \
		drm_memory_debug.o ati_pcigart.o drm_sman.o \
		drm_hashtab.o drm_mm.o drm_object.o drm_compat.o \
	        drm_fence.o drm_ttm.o drm_bo.o drm_bo_move.o drm_crtc.o \
		drm_edid.o drm_modes.o drm_bo_lock.o drm_regman.o drm_vm_nopage_compat.o
psb-objs := psb_drv.o psb_mmu.o psb_sgx.o psb_irq.o psb_fence.o \
		psb_buffer.o psb_gtt.o psb_setup.o psb_i2c.o psb_fb.o \
		psb_schedule.o psb_scene.o psb_reset.o \
		psb_regman.o psb_xhw.o psb_msvdx.o psb_msvdxinit.o \
		psb_detear.o


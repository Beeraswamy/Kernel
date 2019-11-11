#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x4d5503c4, "module_layout" },
	{ 0x621a18bd, "cdev_del" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x2753ef5c, "cdev_add" },
	{ 0x26a0a5cf, "cdev_init" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0xb00ccc33, "finish_wait" },
	{ 0xe75663a, "prepare_to_wait" },
	{ 0x4292364c, "schedule" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x28171c5b, "current_task" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0xf09c7f68, "__wake_up" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0x94d32a88, "__tracepoint_module_get" },
	{ 0x50eedeb8, "printk" },
	{ 0x3bfc7307, "module_put" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "001CB761EA348369DBF8067");

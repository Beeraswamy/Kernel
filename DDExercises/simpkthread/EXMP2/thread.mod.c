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
	{ 0xbed2a05a, "call_usermodehelper_setfns" },
	{ 0x48cf0477, "call_usermodehelper_exec" },
	{ 0x4ff1c9bc, "populate_rootfs_wait" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0x28171c5b, "current_task" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
	{ 0xd79b5a02, "allow_signal" },
	{ 0x4292364c, "schedule" },
	{ 0x3f1bc368, "call_usermodehelper_setup" },
	{ 0xe75663a, "prepare_to_wait" },
	{ 0xb00ccc33, "finish_wait" },
	{ 0x7e9ebb05, "kernel_thread" },
	{ 0xdc43a9c8, "daemonize" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "EE091E07BE8553D34DFF770");

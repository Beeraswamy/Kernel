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
	{ 0x83636ee3, "wait_for_completion" },
	{ 0x7e9ebb05, "kernel_thread" },
	{ 0x7f114141, "complete_and_exit" },
	{ 0x50eedeb8, "printk" },
	{ 0xb00ccc33, "finish_wait" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0xe75663a, "prepare_to_wait" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xe174aa7, "__init_waitqueue_head" },
	{ 0xfb6af58d, "recalc_sigpending" },
	{ 0xdc43a9c8, "daemonize" },
	{ 0x28171c5b, "current_task" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D9D3EF09D25F43CBCF0605D");

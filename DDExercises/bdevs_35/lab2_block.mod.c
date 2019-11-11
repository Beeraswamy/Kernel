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
	{ 0xa90c928a, "param_ops_int" },
	{ 0x9c1e6e96, "blk_cleanup_queue" },
	{ 0x22c5cac8, "put_disk" },
	{ 0x2b376525, "del_gendisk" },
	{ 0x693932dc, "add_disk" },
	{ 0xe914e41e, "strcpy" },
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0x21270eff, "alloc_disk" },
	{ 0x999e8297, "vfree" },
	{ 0x71a50dbc, "register_blkdev" },
	{ 0x2bf6ec9e, "blk_queue_logical_block_size" },
	{ 0x35019e16, "blk_init_queue" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xa72f312, "__blk_end_request_cur" },
	{ 0x2e60bace, "memcpy" },
	{ 0xa16346a9, "blk_fetch_request" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "9E63C4ACB163DDC2E17D48A");

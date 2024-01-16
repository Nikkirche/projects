#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xf704969, "module_layout" },
	{ 0xd731cdd9, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x193e7be6, "kernel_sendmsg" },
	{ 0x754d539c, "strlen" },
	{ 0x1b6314fd, "in_aton" },
	{ 0xada2cc9e, "sock_release" },
	{ 0x755a0fd9, "init_user_ns" },
	{ 0xb60ac377, "sock_create_kern" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3d0a55bc, "d_add" },
	{ 0xcad5da9b, "mount_nodev" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xfb578fc5, "memset" },
	{ 0xdc79380f, "kernel_connect" },
	{ 0x5a921311, "strncmp" },
	{ 0x180e8901, "kernel_sock_shutdown" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0xa21071e2, "init_net" },
	{ 0x61651be, "strcat" },
	{ 0xa916b694, "strnlen" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x7c797b6, "kmem_cache_alloc_trace" },
	{ 0xafb9a9a5, "kernel_recvmsg" },
	{ 0x12e21383, "register_filesystem" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xaa2af4ae, "d_make_root" },
	{ 0x4dea0566, "unregister_filesystem" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc16bfbbd, "new_inode" },
	{ 0x5d40dc60, "inode_init_owner" },
	{ 0xe914e41e, "strcpy" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "09B200DF76DD418E5F06C51");

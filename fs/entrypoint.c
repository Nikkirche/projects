#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "nfs.h"
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ivanov Ivan");
MODULE_VERSION("0.01");
int networkfs_init(void) {
  printk(KERN_INFO "Hello, World!\n");
  register_filesystem(&networkfs_fs_type);
  return 0;
}

void networkfs_exit(void) {
  printk(KERN_INFO "Goodbye!\n");
  unregister_filesystem(&networkfs_fs_type);
}

module_init(networkfs_init);
module_exit(networkfs_exit);

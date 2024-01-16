#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "nfs_ops.h"

struct inode *networkfs_get_inode(struct super_block *sb,
                                  const struct inode *dir, umode_t mode,
                                  int i_ino) {
  struct inode *inode;
  inode = new_inode(sb);
  inode->i_ino = i_ino;
  inode->i_op = &networkfs_inode_ops;
  inode->i_fop = &networkfs_dir_ops;
  if (inode != NULL) {
    inode_init_owner(&init_user_ns, inode, dir, mode);
  }
  return inode;
}
int networkfs_fill_super(struct super_block *sb, void *data, int silent) {
  struct inode *inode;
  inode = networkfs_get_inode(sb, NULL, S_IFDIR | 0777, 1000);
  sb->s_root = d_make_root(inode);
  if (sb->s_root == NULL) {
    return -ENOMEM;
  }
  printk(KERN_INFO "%s", sb->s_fs_info);
  printk(KERN_INFO "return 0\n");
  return 0;
}
struct dentry *networkfs_mount(struct file_system_type *fs_type, int flags,
                               const char *token, void *data) {
  struct dentry *ret;
  ret = mount_nodev(fs_type, flags, data, networkfs_fill_super);
  if (ret == NULL) {
    printk(KERN_ERR "Can't mount file system");
  } else {
    printk(KERN_INFO "Mounted successfuly");
  }
  char *token_copy = kmalloc(36, GFP_KERNEL);
  if (token_copy == 0) {
    printk(KERN_ERR "Can't mount file system");
  }
  strcat(token_copy, token);
  ret->d_sb->s_fs_info = token_copy;
  return ret;
}

void networkfs_kill_sb(struct super_block *sb) {
  kfree(sb->s_fs_info);
  printk(KERN_INFO
         "networkfs super block is destroyed. Unmount successfully.\n");
}

struct file_system_type networkfs_fs_type = {.name = "networkfs",
                                             .mount = networkfs_mount,
                                             .kill_sb = networkfs_kill_sb};

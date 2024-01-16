#include <linux/fs.h>
#include <linux/slab.h>

#include "defs.h"
#include "http.h"
#include "linux/string.h"
struct inode *networkfs_get_inode(struct super_block *sb,
                                  const struct inode *dir, umode_t mode,
                                  int i_ino);
struct inode_operations networkfs_inode_ops;
struct file_operations networkfs_dir_ops;
void decode(const char *input, char *output) {
  memset(output, 0, strlen(input) * 3);
  char buff[6];
  for (int i = 0; i < strlen(input); i++) {
    snprintf(buff, 4, "%s%x", "%", input[i]);

    strcat(output, buff);
    pr_info("decoding %s", output);
  }
}
struct dentry *networkfs_lookup(struct inode *parent_inode,
                                struct dentry *child_dentry,
                                unsigned int flag) {
  char *raw_response = kmalloc(sizeof(entry_info), GFP_KERNEL);
  if (raw_response == 0) {
    return -1;
  }
  char pino_c[32];
  const char *name = child_dentry->d_name.name;
  char *decoded_name = kmalloc(strlen(name) * 3, GFP_KERNEL);
  if (decoded_name == 0) {
    return -1;
  }
  decode(name, decoded_name);
  sprintf(pino_c, "%lu", parent_inode->i_ino);
  pr_info("lookup request: starting with name: %s inode %s ", decoded_name,
          &pino_c);

  int64_t code = networkfs_http_call(parent_inode->i_sb->s_fs_info, FS_LOOKUP,
                                     raw_response, BUFFER_SIZE, 2, "parent",
                                     &pino_c, "name", decoded_name);
  pr_info("lookup request: code %llu", code);
  if (code != 0) {
    kfree(raw_response);
    kfree(decoded_name);
    return NULL;
  }
  entry_info *entryInfo = (entry_info *)raw_response;
  ino_t root;
  struct inode *inode;
  root = parent_inode->i_ino;
  if (entryInfo->entry_type == DT_REG) {
    inode = networkfs_get_inode(parent_inode->i_sb, NULL, S_IFREG | 0777,
                                entryInfo->ino);
    d_add(child_dentry, inode);
  } else if (entryInfo->entry_type == DT_DIR) {
    inode = networkfs_get_inode(parent_inode->i_sb, NULL, S_IFDIR | 0777,
                                entryInfo->ino);
    d_add(child_dentry, inode);
  }
  kfree(raw_response);
  kfree(decoded_name);
  return NULL;
}
ino_t abstract_create(struct inode *parent_inode, struct dentry *child_dentry,
                      bool is_file) {
  ino_t root;
  const char *name = child_dentry->d_name.name;
  char *decoded_name = kmalloc(strlen(name) * 3, GFP_KERNEL);
  if (decoded_name == 0) {
    return -1;
  }
  decode(name, decoded_name);
  root = parent_inode->i_ino;
  char *raw_response = kmalloc(BUFFER_SIZE, GFP_KERNEL);
  if (raw_response == 0) {
    return -1;
  }
  char ino_c[30];
  sprintf(ino_c, "%lu", root);
  int64_t code;
  if (!is_file) {
    code = networkfs_http_call(parent_inode->i_sb->s_fs_info, FS_CREATE,
                               raw_response, BUFFER_SIZE, 3, "parent", &ino_c,
                               "name", decoded_name, "type", "directory");
  } else {
    code = networkfs_http_call(parent_inode->i_sb->s_fs_info, FS_CREATE,
                               raw_response, BUFFER_SIZE, 3, "parent", &ino_c,
                               "name", decoded_name, "type", "file");
  }
  pr_info("create request: code %lli", code);
  if (code != 0) {
    kfree(raw_response);
    kfree(decoded_name);
    return 0;
  }
  ino_t *file;
  file = (ino_t *)raw_response;
  kfree(raw_response);
  kfree(decoded_name);

  return *file;
}
int networkfs_mkdir(struct user_namespace *, struct inode *parent_inode,
                    struct dentry *child_dentry, umode_t) {
  struct inode *inode;
  ino_t dir = abstract_create(parent_inode, child_dentry, false);
  if (dir == 0) {
    return 0;
  }
  inode = networkfs_get_inode(parent_inode->i_sb, NULL,
                              S_IFDIR | S_IRWXUGO | 0777, dir);
  pr_info("dir %u ", dir);
  inode->i_op = &networkfs_inode_ops;
  inode->i_fop = &networkfs_dir_ops;
  d_add(child_dentry, inode);
  return 0;
}
int networkfs_create(struct user_namespace *, struct inode *parent_inode,
                     struct dentry *child_dentry, umode_t mode, bool b) {
  struct inode *inode;
  ino_t file = abstract_create(parent_inode, child_dentry, true);
  if (file == 0) {
    return 0;
  }
  inode = networkfs_get_inode(parent_inode->i_sb, NULL,
                              S_IFREG | S_IRWXUGO | 0777, file);
  inode->i_op = &networkfs_inode_ops;
  inode->i_fop = NULL;
  d_add(child_dentry, inode);
  return 0;
}
int abstract_delete(struct inode *parent_inode, struct dentry *child_dentry,
                    bool is_file) {
  ino_t root;
  const char *name = child_dentry->d_name.name;
  root = parent_inode->i_ino;
  char *raw_response;
  char ino_c[10];
  sprintf(ino_c, "%lu", root);
  int64_t code;
  if (is_file) {
    code =
        networkfs_http_call(parent_inode->i_sb->s_fs_info, FS_UNLINK,
                            raw_response, 0, 2, "parent", &ino_c, "name", name);
  } else {
    code =
        networkfs_http_call(parent_inode->i_sb->s_fs_info, FS_RMDIR,
                            raw_response, 0, 2, "parent", &ino_c, "name", name);
  }
  pr_info("create request: code %lli", code);
  kfree(raw_response);
  return code;
}
int networkfs_unlink(struct inode *parent_inode, struct dentry *child_dentry) {
  return abstract_delete(parent_inode, child_dentry, true);
}
int networkfs_rmdir(struct inode *parent_inode, struct dentry *child_dentry) {
  return abstract_delete(parent_inode, child_dentry, false);
}
int networkfs_link(struct dentry *old_dentry, struct inode *parent_dir,
                   struct dentry *new_dentry) {
  char *raw_response;
  char ino_c[32], dino_c[32];
  sprintf(dino_c, "%lu", old_dentry->d_inode->i_ino);
  sprintf(ino_c, "%lu", parent_dir->i_ino);
  pr_info("link request: starting with name: %s inode %s ", &ino_c);
  const char *name = new_dentry->d_name.name;
  char *decoded_name = kmalloc(strlen(name) * 3, GFP_KERNEL);
  decode(name, decoded_name);
  d_add(new_dentry, old_dentry->d_inode);
  int64_t code = networkfs_http_call(parent_dir->i_sb->s_fs_info, FS_LINK,
                                     raw_response, 0, 3, "source", &dino_c,
                                     "parent", &ino_c, "name", decoded_name);
  pr_info("link request: code %lli", code);
  return 0;
}
struct inode_operations networkfs_inode_ops = {.lookup = networkfs_lookup,
                                               .create = networkfs_create,
                                               .mkdir = networkfs_mkdir,
                                               .rmdir = networkfs_rmdir,
                                               .unlink = networkfs_unlink,
                                               .link = networkfs_link};

int networkfs_iterate(struct file *filp, struct dir_context *ctx) {
  char fsname[256];
  struct dentry *dentry;
  struct inode *inode;
  unsigned long offset;
  int stored;
  unsigned char ftype;
  ino_t ino;
  ino_t dino;
  dentry = filp->f_path.dentry;
  inode = dentry->d_inode;
  offset = filp->f_pos;
  stored = 0;

  ino = inode->i_ino;
  char *raw_response = kmalloc(BUFFER_SIZE, GFP_KERNEL);
  if (raw_response == 0) {
    return -1;
  }
  pr_info("iterate list request: starting with inode:   %lu ", ino);

  char ino_c[32];
  sprintf(ino_c, "%lu", ino);
  pr_info("%s", inode->i_sb->s_fs_info);
  int64_t code =
      networkfs_http_call(inode->i_sb->s_fs_info, FS_LIST, raw_response,
                          BUFFER_SIZE, 1, "inode", &ino_c);

  pr_info("iterate list  request: code %lli", code);
  if (code != 0) {
    kfree(raw_response);
    return 0;
  }
  entries *dir_info = (entries *)(raw_response);
  if (offset >= dir_info->entries_count + 2) {
    kfree(raw_response);
    return 0;
  }
  pr_info("%zu %u %lu", dir_info->entries_count, stored, offset);
  while (true) {
    if (offset == 0) {
      strcpy(fsname, ".");
      ftype = DT_DIR;
      dino = ino;
    } else if (offset == 1) {
      strcpy(fsname, "..");
      ftype = DT_DIR;
      dino = dentry->d_parent->d_inode->i_ino;
    } else if (stored < dir_info->entries_count + 2) {
      struct entry cur = dir_info->entries[stored - 2];
      pr_info("%zu", cur.ino);
      dino = cur.ino;
      ftype = cur.entry_type;
      strcpy(fsname, cur.name);

    } else {
      kfree(raw_response);
      break;
    }
    stored++;
    offset++;
    ctx->pos = offset;
    dir_emit(ctx, fsname, strlen(fsname), dino, ftype);
  }
  pr_info("%u test u", stored);
  return 0;
}

struct file_operations networkfs_dir_ops = {
    .iterate = networkfs_iterate,
};

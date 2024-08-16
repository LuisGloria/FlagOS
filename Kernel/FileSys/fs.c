#include "fs.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    uint32_t size;
    uint32_t block_size;
} superblock_t;

typedef struct {
    uint32_t inode_number;
    uint32_t size;
    uint32_t permissions;
} inode_t;

typedef struct {
    char name[256];
    uint32_t inode_number;
} directory_entry_t;

superblock_t superblock;
inode_t *inodes;
directory_entry_t *directory;

// Function implementations

int fs_mount(const char *device) {
    printf("Mounting filesystem on %s\n", device);
    return 0;
}

int fs_unmount(void) {
    printf("Unmounting filesystem\n");
    return 0;
}

int fs_create(const char *path, uint32_t permissions) {
    printf("Creating file %s with permissions %u\n", path, permissions);
    return 0;
}

int fs_delete(const char *path) {
    printf("Deleting file %s\n", path);
    return 0;
}

int fs_read(const char *path, void *buffer, uint32_t size, uint32_t offset) {
    printf("Reading %u bytes from file %s at offset %u\n", size, path, offset);
    return 0;
}

int fs_write(const char *path, const void *buffer, uint32_t size, uint32_t offset) {
    printf("Writing %u bytes to file %s at offset %u\n", size, path, offset);
    return 0;
}

int fs_list(const char *path) {
    printf("Listing files in directory %s\n", path);
    return 0;
}

int fs_mkdir(const char *path) {
    printf("Creating directory %s\n", path);
    return 0;
}

int fs_rmdir(const char *path) {
    printf("Removing directory %s\n", path);
    return 0;
}

#ifndef FS_H
#define FS_H

#include <stdint.h>

// Constants for the file system
#define FS_BLOCK_SIZE 4096
#define FS_MAX_FILES 128
#define FS_FILENAME_LEN 32

// File system structures

// Superblock structure
typedef struct {
    uint32_t magic;              // Magic number to identify the file system
    uint32_t block_size;         // Block size of the file system
    uint32_t num_blocks;         // Total number of blocks
    uint32_t num_files;          // Number of files in the file system
} superblock_t;

// Directory entry structure
typedef struct {
    char filename[FS_FILENAME_LEN];
    uint32_t inode_index;       // Index to the file's metadata
} dir_entry_t;

// Inode structure
typedef struct {
    uint32_t size;              // Size of the file
    uint32_t blocks;            // Number of blocks used by the file
    uint32_t block_indexes[12]; // Direct block pointers (simple design)
} inode_t;

// File structure
typedef struct {
    inode_t *inode;             // Pointer to the file's inode
    uint32_t current_pos;       // Current position in the file
} file_t;

// File system functions
void fs_init(void);
void fs_mount(void);
file_t* fs_open(const char *filename);
void fs_close(file_t *file);
int fs_read(file_t *file, void *buffer, uint32_t size);
int fs_write(file_t *file, const void *buffer, uint32_t size);

#endif // FS_H

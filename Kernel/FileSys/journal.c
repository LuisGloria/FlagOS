#include <stdio.h>
#include "heap.h"

// Journaling function obviously
void journal_log(const char *operation, const char *details) {
    printf("Journal log: %s - %s\n", operation, details);
}

int fs_create(const char *path, uint32_t permissions) {
    journal_log("CREATE", path);
    return 0;
}
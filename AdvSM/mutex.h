#ifndef MUTEX_H
#define MUTEX_H
#include "proccess.h"

typedef struct mutex {
    int locked;
    process_t *owner;
} mutex_t;

void mutex_lock(mutex_t *mutex);
void mutex_unlock(mutex_t *mutex);

#endif

#ifndef CONTEXT_SWITCH_H
#define CONTEXT_SWITCH_H

#include "process.h"

void context_switch(process_t *current, process_t *next);

#endif

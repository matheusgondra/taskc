#pragma once

#include <stdint.h>

typedef enum {
    STATUS_TODO,
    STATUS_IN_PROGRESS,
    STATUS_DONE
} TaskStatus;

typedef struct {
    uint64_t id;
    char *description;

} Task;
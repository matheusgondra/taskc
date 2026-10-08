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
    TaskStatus status;
    uint64_t created_at;
    uint64_t updated_at;
} Task;

Task task_create(uint64_t id, const char *description);
void task_destroy(Task *task);
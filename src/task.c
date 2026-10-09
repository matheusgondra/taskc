#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

Task task_create(uint64_t id, const char *description) {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    Task task = {.id = id,
                 .description = strdup(description),
                 .status = STATUS_TODO,
                 .created_at = (uint64_t) ts.tv_sec,
                 .updated_at = (uint64_t) ts.tv_sec};

    return task;
}

void task_destroy(Task *task) {
    if (task->description) {
        free(task->description);
        task->description = nullptr;
    }
}
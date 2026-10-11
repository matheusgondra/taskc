#include "task.h"
#include "unity.h"
#include <string.h>

void setUp() {}

void tearDown() {}

void test_task_create_should_initialize_fields_correctly() {
    Task sut = task_create(1, "any description");

    TEST_ASSERT_EQUAL_UINT64(1, sut.id);
    TEST_ASSERT_EQUAL_STRING("any description", sut.description);
    TEST_ASSERT_EQUAL_INT(STATUS_TODO, sut.status);
    TEST_ASSERT_GREATER_THAN_UINT64(0, sut.created_at);
    TEST_ASSERT_GREATER_THAN_UINT64(0, sut.updated_at);
    TEST_ASSERT_EQUAL_UINT64(sut.created_at, sut.updated_at);

    task_destroy(&sut);
}

void test_task_create_should_duplicate_description_string() {
    char source_buffer[30] = "any description";
    Task sut = task_create(1, source_buffer);

    strcpy(source_buffer, "modified description");

    TEST_ASSERT_EQUAL_STRING("any description", sut.description);

    task_destroy(&sut);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_task_create_should_initialize_fields_correctly);
    RUN_TEST(test_task_create_should_duplicate_description_string);

    return UNITY_END();
}
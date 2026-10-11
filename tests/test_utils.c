#include "unity.h"
#include "utils.h"

void setUp() {}

void tearDown() {}

void test_parse_uint64_should_return_false_when_given_null_string() {
    uint64_t value;

    TEST_ASSERT_FALSE(parse_uint64(nullptr, &value));
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_parse_uint64_should_return_false_when_given_null_string);

    return UNITY_END();
}
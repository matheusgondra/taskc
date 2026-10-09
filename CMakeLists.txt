cmake_minimum_required(VERSION 3.25)
project(taskc VERSION 1.0.0 LANGUAGES C DESCRIPTION "Task tracker CLI")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE LIB_SOURCES "src/*.c")
list(FILTER LIB_SOURCES EXCLUDE REGEX "src/main\\.c$")

add_library(${PROJECT_NAME}_lib STATIC ${LIB_SOURCES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        unity
        GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
        GIT_TAG        v2.7.0
    )
    FetchContent_MakeAvailable(unity)

    function(add_unity_test target_name source_file)
        add_executable(${target_name} ${source_file})
        target_link_libraries(${target_name} PRIVATE ${PROJECT_NAME}_lib unity)

        add_test(NAME ${target_name} COMMAND ${target_name})
    endfunction()

endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
    file(GLOB_RECURSE FORMAT_FILES
        "src/*.c"
        "include/*.h"
        "tests/*.c"
    )

    add_custom_target(format
        COMMAND ${CLANG_FORMAT} -i ${FORMAT_FILES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Formatando codigo com clang-format..."
    )
endif()
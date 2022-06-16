cmake_minimum_required(VERSION 3.9)

project(tc++pl4 CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# compiler flags
if (MSVC)
  add_compile_options(/IW4 /WX)
else()
  add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

# Conan!
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# The exercises themselves
file(GLOB_RECURSE exercises CONFIGURE_DEPENDS "src/x*.cpp")
foreach (exercise ${exercises})
  get_filename_component(exercise_name ${exercise} NAME_WLE)
  add_executable(${exercise_name} ${exercise})
  target_compile_definitions(${exercise_name} PUBLIC EXERCISE_MAIN)
  set_target_properties(${exercise_name} PROPERTIES OUTPUT_NAME ${exercise_name})
endforeach()

# TESTS + BENCHMARKS
set(TESTS_NAME ${PROJECT_NAME}_tests)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${TESTS_NAME} ${sources} "test/main.cpp")
target_link_libraries(${TESTS_NAME} PRIVATE ${CONAN_LIBS})
target_compile_definitions(${TESTS_NAME} PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=60)
target_compile_definitions(${TESTS_NAME} PRIVATE EXERCISE_TESTS)
target_compile_definitions(${TESTS_NAME} PRIVATE EXERCISE_BENCHMARKS)
set_target_properties(${TESTS_NAME} PROPERTIES OUTPUT_NAME run-tests)

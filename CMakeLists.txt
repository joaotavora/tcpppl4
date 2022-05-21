cmake_minimum_required(VERSION 3.9)

project(tc++pl4 CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/vendor/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})
find_package(Sanitizers)        # bring in "add_sanitizers" function

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# compiler flags
if (MSVC)
  add_compile_options(/IW4 /WX)
else()
  add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

# CORE LIB
# set(CORE_LIB_NAME ${PROJECT_NAME}) # will make e.g. libtc++pl4.a
# file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")
# add_library(${CORE_LIB_NAME} STATIC ${sources})
# add_sanitizers(${CORE_LIB_NAME})
# target_include_directories(${CORE_LIB_NAME} PUBLIC ./src)

# APPLICATIONS
file(GLOB_RECURSE exercises CONFIGURE_DEPENDS "src/x*.cpp")
foreach (exercise ${exercises})
  #  THe define is missing
  get_filename_component(exercise_name ${exercise} NAME_WLE)
  add_executable(${exercise_name} ${exercise})
  target_compile_definitions(${exercise_name} PUBLIC EXERCISE_MAIN)
  add_sanitizers(${exercise_name})
  set_target_properties(${EXAMPLE_NAME} PROPERTIES OUTPUT_NAME src/${exercise_name})
endforeach()

# TESTS + BENCHMARKS
set(TESTS_NAME ${PROJECT_NAME}_tests)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${TESTS_NAME} ${sources} "test/main.cpp")
add_sanitizers(${TESTS_NAME})
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL
  "Suppressing google benchmark's self tests" FORCE)
add_subdirectory(vendor/benchmark)
add_subdirectory(vendor/catch)
target_link_libraries(${TESTS_NAME} benchmark catch)
target_compile_definitions(${TESTS_NAME} PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=60)
target_compile_definitions(${TESTS_NAME} PRIVATE EXERCISE_TESTS)
target_compile_definitions(${TESTS_NAME} PRIVATE EXERCISE_BENCHMARKS)
set_target_properties(${TESTS_NAME} PROPERTIES OUTPUT_NAME run-tests)

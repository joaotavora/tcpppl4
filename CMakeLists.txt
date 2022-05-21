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
set(CORE_LIB_NAME ${PROJECT_NAME}) # will make e.g. libtc++pl4.a
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/**/*.cpp")
add_library(${CORE_LIB_NAME} STATIC src/main.cpp ${sources})
add_sanitizers(${CORE_LIB_NAME})
target_include_directories(${CORE_LIB_NAME} PUBLIC ./src)

# APPLICATION
set(EXAMPLE_NAME ${PROJECT_NAME}_app)
add_executable(${EXAMPLE_NAME} src/main.cpp)
add_sanitizers(${EXAMPLE_NAME})
target_link_libraries(${EXAMPLE_NAME} PRIVATE ${CORE_LIB_NAME})
set_target_properties(${EXAMPLE_NAME} PROPERTIES OUTPUT_NAME src/${PROJECT_NAME})

# TESTS + BENCHMARKS
set(TESTS_NAME ${PROJECT_NAME}_tests)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "test/*.cpp")
add_executable(${TESTS_NAME} ${sources})
add_sanitizers(${TESTS_NAME})
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's self tests" FORCE)
add_subdirectory(vendor/benchmark)
add_subdirectory(vendor/catch)
target_link_libraries(${TESTS_NAME} PRIVATE ${CORE_LIB_NAME} benchmark catch)
target_compile_definitions(${TESTS_NAME} PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=60)
set_target_properties(${TESTS_NAME} PROPERTIES OUTPUT_NAME run-tests)

# JUST BENCHMARKS (no need to build for non-release builds)
if (CMAKE_BUILD_TYPE MATCHES Release)
  set(BENCH_NAME ${PROJECT_NAME}_bench)
  file(GLOB_RECURSE sources CONFIGURE_DEPENDS "bench/*.cpp")
  add_executable(${BENCH_NAME} ${sources})
  target_link_libraries(${BENCH_NAME} PRIVATE ${CORE_LIB_NAME} benchmark)
  target_compile_options(${BENCH_NAME} PRIVATE -march=native -mtune=native)
  set_target_properties(${BENCH_NAME} PROPERTIES OUTPUT_NAME run-benchmarks)
endif ()

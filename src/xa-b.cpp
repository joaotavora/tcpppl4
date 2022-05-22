#include <type_traits>
#include <cstdio>

#ifdef EXERCISE_TESTS
#include "catch.hpp"
TEST_CASE("xa-b"){
  REQUIRE(true);
}
#endif

#ifdef EXERCISE_BENCHMARKS
#include "benchmark/benchmark.h"
static void BM_super_fast(benchmark::State& state)
{
  for (auto _ : state) {};
}
BENCHMARK(BM_super_fast);
#endif

#ifdef EXERCISE_MAIN
int main() {
  puts(std::is_signed_v<char>?"signed":"unsigned");
}
#endif

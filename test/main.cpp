#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "benchmark/benchmark.h"

int main(int argc, char** argv) {
  int result = Catch::Session().run(argc, argv);

  if (result != 0) return result;

  // TODO(capitaomorte): pass arguments to Google benchmark, too
  ::benchmark::Initialize(0, nullptr);
  ::benchmark::RunSpecifiedBenchmarks();
}

// #define CATCH_CONFIG_MAIN // This tells Catch to provide a main()
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int main(int argc, char** argv) {
  int result = Catch::Session().run(argc, argv);
  if (result != 0) return result;
}

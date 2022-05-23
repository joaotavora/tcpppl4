/** (∗2) Time a loop. Write out the time in milliseconds. Do this for
the default setting of your compiler and for a setting using an
optimizer (e.g., −O2 or "release"). Be careful not to have the
optimizer eliminate your whole loop as dead code because you did not
use a result. */

#include <chrono>
#include <random>
#include <iostream>
using namespace std; //NOLINT

#ifdef EXERCISE_MAIN
int main() {
  int n = 1 << 20;
  int total = 0;
  mt19937 gen{0};
  uniform_int_distribution<> distro{-200, 200};
  auto t1{chrono::high_resolution_clock::now()};
  for (int i = 0; i<n; ++i) total += distro(gen);
  auto t2{chrono::high_resolution_clock::now()};
  std::cout << "Took "
            << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count()
            << "ms to sum " << n << " random numbers\n";
  std::cout << total << "\n";
}
#endif

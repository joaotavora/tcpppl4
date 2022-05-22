/** [9] (∗1) Open a file for writing (as an ofstream) and write a few
    hundred integers to it. */

#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

using namespace std; //NOLINT

#ifdef EXERCISE_MAIN
int main(int argc, char* argv[]) {
  vector<string> args(argv, argv + argc);
  if (args.size() != 2) throw runtime_error("Need a filename");
  ofstream of{args[1]};
  int n{300};
  std::mt19937 gen{0};
  uniform_int_distribution<> distro{-200, 200};
  while (n--) { //NOLINT
    of << distro(gen) << " ";
  }
}
#endif

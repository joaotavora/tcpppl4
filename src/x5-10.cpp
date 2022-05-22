/** [9] (∗1) Open the file of integers from §X.5[9] for reading (as an
    ifstream) and read it. */

#include <fstream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

#include "common.hpp"

using namespace std; //NOLINT

#ifdef EXERCISE_MAIN
int main(int argc, char* argv[]) {
  vector<string> args(argv, argv+argc);
  if (args.size() != 2) throw runtime_error("Need a filename");
  ifstream in_f{args[1]};
  vector<int> v(istream_iterator<int>{in_f},
                istream_iterator<int>{});
  print_sequence(v, cout);
}
#endif

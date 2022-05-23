/** [5] (∗1.5) Use a regex to find all decimal numbers in a file.*/

#include <regex>
#include <string>
#include <iostream>

using namespace std; //NOLINT

#ifdef EXERCISE_MAIN
int main() {
  int lineno{0};
  regex re{"[+-]?[0-9]+(?:\\.?[0-9]+)?"};

  for (string probe{}; std::getline(cin, probe);) {
    ++lineno;
    smatch matches;
    auto from{cbegin(probe)};
    while (regex_search(from, cend(probe), matches, re)) {
      cout << lineno << ":" << matches[0] << "\n";
      from = matches.suffix().first;
    }
  }
}
#endif

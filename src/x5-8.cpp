/** Repeat §X.5[7] with a vector<string> initialized with "Kant",
    "Plato", "Aristotle", "Kierkegard", and "Hume" */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std; //NOLINT

template <typename C>
void print_sequence(C c) {
  cout << "{";
  if (!c.empty()) {
    auto beg{begin(c)};
    cout << *beg;
    for_each(beg+1, end(c), [](const auto& e) {
      cout << "," << e;
    });
  }
  cout << "}";
}

#ifdef EXERCISE_MAIN
int main() {
  vector<string> vs{"Kant", "Plato", "Aristotle", "Kierkegard", "Hume"};
  print_sequence(vs);
  cout << "\n";
  sort(begin(vs), end(vs));
  print_sequence(vs);
  cout << "\n";
}
#endif

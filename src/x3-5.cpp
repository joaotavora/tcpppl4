#include <iostream>

#ifdef EXERCISE_MAIN
int main() {
  using std::cout;

  cout << "A bool: "     << false << '\n'
       << "A char: "     << 'c' << '\n'
       << "An int: "     << 42 << '\n'
       << "A double: "   << 42.42 << '\n'
       << "A string: \"" << std::string{"foobar baz"} << "\"\n";
}
#endif

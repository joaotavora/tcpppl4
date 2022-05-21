#include <iostream>

#ifdef EXERCISE_MAIN
int main() {
  using std::cout, std::cin, std::cerr, std::string;

  bool   b{};
  char   c{};
  int    i{};
  double d{};
  string s{};

  cout << "Enter a bool, a char, an int, a double and a string:\n";

  cin >> b >> c >> i >> d >> s;

  if (cin.fail())
    cerr << "Ooops!\n";
  else {
    cout << "A bool: "     << b << '\n'
         << "A char: "     << c << '\n'
         << "An int: "     << i << '\n'
         << "A double: "   << d << '\n'
         << "A string: \"" << s << "\"\n";
  }
}
#endif

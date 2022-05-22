/**
    Redo §X.5[5], storing several (name,age) pairs in a class. Doing
    the reading and writ- ing using your own >> and << operators
*/

#include <iostream>
#include <vector>
using std::cin, std::cout, std::cerr, std::string,
  std::ostream, std::istream;

struct Person {
  string name{};
  int age{};
};

ostream& operator<<(ostream& o, const Person& p) {
  return o << "{"
           << "name: \"" << p.name << "\"" << ", "
           << "age: " << p.age
           << "}";
}

istream& operator>>(istream& i, Person& p) {
  char c{};
  string s{};
  int a{};
  while (i && i.get(c)) {
    if (c == ',') break;
    s.push_back(c);
  }
  i >> a;
  if (!i.fail()) {
    p.name = std::move(s);
    p.age = a;
  }
  return i;
}

#ifdef EXERCISE_MAIN
int main() {
  Person p;
  std::vector<Person> vp{};

  while (true) {
    cout << "Reading a new one\n";
    cin >> p; 
    if (cin.eof()) break;
    if (cin.fail()) {
      cout << "Oops\n";
      cin.clear();
    } else {
      vp.push_back(p);
    }
    while (cin.peek() != '\n') cin.get();
    cin.get();
  }
  for (const auto& p : vp) cout << p << "\n";
}
#endif

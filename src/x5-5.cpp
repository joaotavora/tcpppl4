/**
    Write a program that reads a name (a string) and an age (an int)
    from the standard input stream cin. Then output a message
    including the name and age to the standard output stream cout.
*/

#include <iostream>
using std::cin, std::cout, std::cerr, std::string;
#ifdef EXERCISE_MAIN
int main() {
  string name{};
  int age{};
  std::getline(cin, name);
  cin >> age;
  if (cin.fail()) {cerr << "Something's wrong\n"; return -1;}
  cout << "Name is " << name << " and age is " << age << "\n";
}
#endif

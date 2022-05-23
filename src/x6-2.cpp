/** (∗1.5) Write a program with two treads: one that writes hello ev
    ery second and one that writes world! ev ery second. */

#include <thread>
#include <iostream>
using namespace std; // NOLINT

#ifdef EXERCISE_MAIN
int main() {
  // https://stackoverflow.com/a/6374525/177259
  thread t1{[]{while (1) {cout << "Hello\n"; this_thread::sleep_for(1s);}}};
  thread t2{[]{while (1) {cout << "world\n"; this_thread::sleep_for(1s);}}};
  t1.join();
  t2.join();
}
#endif

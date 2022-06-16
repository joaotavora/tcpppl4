/** (∗1.5) Write a program with two treads: one that writes hello ev
    ery second and one that writes world! ev ery second. */

#include <thread>
#include <iostream>

#ifdef EXERCISE_MAIN
int main() {
  using namespace std::literals::chrono_literals;

  // https://stackoverflow.com/a/6374525/177259
  std::thread t1{[]{while (true) {std::cout << "Hello\n"; std::this_thread::sleep_for(1s);}}};
  std::thread t2{[]{while (true) {std::cout << "world\n"; std::this_thread::sleep_for(1s);}}};
  t1.join();
  t2.join();
}
#endif

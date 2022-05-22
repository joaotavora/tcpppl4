/**
  Initialize a vector<int> with the elements 5, 9, −1, 200, and
  0. Print it. Sort is, and print it again.
*/

#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; // NOLINT

template <typename In, typename BinFn>
void for_each_2(In first, In last, BinFn fn) {
  if (first != last) {
    auto second{first + 1};
    while (second != last) {
      fn(*first, *second);
      ++first; ++second;
    }
  }
}

template <typename In, typename Out, typename BinFn>
void copy_each_2(In first, In last,
                 Out out, BinFn fn) {
  for_each_2(first, last, [&](const auto& a, const auto& b){
    *out++ = fn(a, b);
  });
}

void print_vec(vector<int> v) {
  cout << "{";
  if (!v.empty()) {
    auto beg{begin(v)};
    cout << *beg;
    for_each_2(beg, end(v), [](const auto&, const auto& b) {
      cout << "," << b;
    });
  }
  cout << "}";
}

void print_vec_2(vector<int> v) {
  cout << "{";
  ostream_iterator<int> oo{cout, ","};
  copy_each_2(begin(v), end(v), oo, [](const auto& a, const auto&) {
    return a;
  });
  cout << *rbegin(v);
  cout << "}";
}

#ifdef EXERCISE_MAIN
int main() {
  vector<int> vi{5,9,-1,200,0};
  print_vec_2(vi);
  cout << "\n";
  sort(begin(vi), end(vi));
  print_vec_2(vi);
  cout << "\n";
}
#endif

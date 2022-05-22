#include <algorithm>

template <typename C, typename Out>
void print_sequence(C c, Out& o) {
  o << "{";
  if (!c.empty()) {
    auto beg{std::begin(c)};
    o << *beg;
    std::for_each(beg+1, std::end(c), [&o](const auto& e) {
      o << "," << e;
    });
  }
  o << "}";
}

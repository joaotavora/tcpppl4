/** (∗2) Repeat the histogram drawing example from §5.6.3 for a
    normal_distribution and 30 rows. */

/** FIXME: Not too happy about this implementation:

    bucket_idx should maybe be in a histogram class so I can use
    partial specialization for different distributions.

    even in this form, I suspect the histogram is slightly distorted.
    */

#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

#include "common.hpp"

using namespace std; //NOLINT

template <typename Distro, typename Number>
size_t bucket_idx(const Distro& d, Number sample, size_t nbuckets) {
  assert(sample <= d.b());  // NOLINT
  assert(sample >= d.a());  // NOLINT

  size_t idx(nbuckets * (sample - d.a())/(d.b() - d.a()));
  return std::clamp<size_t>(idx, 0, nbuckets - 1);
}

template <>
size_t bucket_idx<normal_distribution<double>, double>
(const normal_distribution<double>& d, double sample, size_t nbuckets) {
  size_t idx(size_t(double(nbuckets) * (sample - d.mean()
                                        + 3*d.stddev())/(6*d.stddev())));
  return std::clamp<size_t>(idx, 0, nbuckets - 1);
}

#ifdef EXERCISE_MAIN
int main() {
  int n{1 << 22};
  normal_distribution<double> distro{-200, 200};
  // uniform_int_distribution<int> distro{0, 1000};
  vector<int> buckets(30, 0);
  mt19937 gen{0};

  for (int i{0}; i<n; ++i) {
    auto idx{bucket_idx(distro, distro(gen), buckets.size())};
    buckets[idx]++;
  }

  auto max{max_element(begin(buckets), end(buckets))};
  size_t maxlen = 40;
  for (const auto& b : buckets) {
    size_t idx = &b - &buckets[0];
    cout << "[" << setw(2) << idx << "] "
         << string(size_t((b / double(*max)) * double(maxlen)), '*') << "\n";
  }
}
#endif


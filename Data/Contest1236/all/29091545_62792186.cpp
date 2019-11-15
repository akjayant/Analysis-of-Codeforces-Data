#include <deque>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <map>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <unordered_map>

using namespace std;

constexpr int64_t MOD = 1'000'000'007;

static unordered_map<int64_t, unordered_map<int64_t, int64_t>> cache;

int64_t modpow(int64_t base, int64_t exp) {
  if (exp == 0) {
    return 1;
  } else if (exp == 1) {
    return base;
  } else {
    auto iter = cache[base].find(exp);
    if (iter != cache[base].end()) {
      return iter->second;
    }

    const auto half = exp / 2LL;
    const auto otherhalf = exp - half;
    const auto ans = (modpow(base, half) * modpow(base, otherhalf)) % MOD;
    cache[base][exp] = ans;
    return ans;
  }
}

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m;
  cin >> n >> m;

  int64_t a = modpow(2, m);
  a = (a + MOD - 1) % MOD;
  int64_t ans = modpow(a, n);

  cout << ans << endl;

  return 0;
}

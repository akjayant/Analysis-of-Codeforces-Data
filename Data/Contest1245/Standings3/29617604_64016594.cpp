#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>

using namespace std;

const int MOD = 1'000'000'007;

int mul(int a, int b) {
  return (1ll * a * b) % MOD;
}

int add(int a, int b) {
  return (0ll + a + b) % MOD;
}

int main() {
  string s;
  cin >> s;
  vector<int> fib(s.size() + 1);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < s.size() + 1; ++i) {
    fib[i] = add(fib[i - 1], fib[i - 2]);
  }

  for (auto ch : s) {
    if (ch == 'm' || ch == 'w') {
      cout << 0 << endl;
      return 0;
    }
  }

  int res = 1;
  int begind = 0;
  while (begind < s.size()) {
    int first = begind;
    while (begind + 1 < s.size() && s[begind] == s[begind + 1]) {
      ++begind;
    }
    ++begind;
    if (s[first] == 'u' || s[first] == 'n') {
      res = mul(res, fib[begind - first]);
    }
  }

  cout << res << endl;
  return 0;
}
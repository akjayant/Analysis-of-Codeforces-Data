#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a + b - mod * (a + b >= mod);
}

int mul(int a, int b) {
  return int(1ll * a * b % mod);
}

int power(int a, int x) {
  if (x == 0) {
    return 1;
  }
  return mul(power(mul(a, a), x >> 1), (x & 1 ? a : 1));
}

int divide(int a, int b) {
  return mul(a, power(b, mod - 2));
}

int sub(int a, int b) {
  return a - b + mod * (a < b);
}

int dp[100228];

int get(string s, char c) {
  int cnt = 0;
  int ans = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == c) {
      ++cnt;
    } else {
      ans = mul(ans, dp[cnt]);
      cnt = 0;
    }
  }
  return mul(ans, dp[cnt]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  cin >> s;
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= s.size(); ++i) {
    dp[i] = add(dp[i - 1], dp[i - 2]);
  }
  for (char c : s) {
    if (c == 'w' or c == 'm') {
      cout << 0;
      return 0;
    }
  }
  cout << mul(get(s, 'u'), get(s, 'n'));

  return 0;
}
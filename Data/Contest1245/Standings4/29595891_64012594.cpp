#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define debug(n1) cout << n1 << endl;
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

const string __sep = "\n";

const ll MOD = 1000000007ll;


ll fib[100001];

ll calc(int len) {
  return fib[len];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  string s;
  cin >> s;
  int n = s.length();
  fib[0] = fib[1] = 1;
  for (int i = 2; i <= n; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  vector<int> lens;
  for (int i =0; i < s.length();) {
    if (s[i] == 'm' || s[i] == 'w') {
      cout << 0 << "\n";
      return 0;
    }
    int len = 0;
    while (i < n && s[i] == 'n')  {++len; ++i;}
    if (len > 1) lens.push_back(len);
    len = 0;
    while (i < n && s[i] == 'u')  {++len; ++i;}
    if (len > 1) lens.push_back(len);
    if (s[i] != 'n' && s[i] != 'u') ++i;
  }
  ll res = 1ll;
  for (int len : lens) {
    res = (res * calc(len)) % MOD;
  }
  cout << res << endl;



  return 0;
}

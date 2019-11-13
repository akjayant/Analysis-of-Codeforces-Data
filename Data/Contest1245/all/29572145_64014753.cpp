// Author: Kamil Nizinski
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define dbg_arr(arr_name, first, last)
#define dbg(...)
#define cerr if (false) cerr
#define speed_of_cin_and_cout ios_base::sync_with_stdio(0), cin.tie(0)
#define local if (false)
#else
#include "debug.h"
#define dbg_arr(arr_name, first, last) cerr << "[" << #arr_name << "[" << #first << " = " << first << " .. " << #last << " = " << last << ")]: " << to_string(arr_name, first, last) << endl
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define speed_of_cin_and_cout
#define local
#endif
#define ft first
#define sd second
#define psb push_back
#define sz(a) static_cast<int>(a.size())
using namespace std;
typedef int64_t LL;
typedef uint64_t LLU;
typedef double DD;
typedef pair<int, int> PII;
const int kMod = 1000000007;
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = 1ll * p.first * ((2 * p.second % kMod + kMod - p.first) % kMod) % kMod;
    int d = (1ll * p.first * p.first % kMod + 1ll * p.second * p.second % kMod) % kMod;
    if (n & 1)
        return {d, (c + d) % kMod};
    else
        return {c, d};
}
void solve() {
  static string s;
  cin >> s;
  int n = sz(s);
  int result = 1;
  for (int i = 0; i < n; i++) if (s[i] == 'w' || s[i] == 'm') {
    cout << "0\n";
    return;
  }
  for (int i = 0; i < n;) if (s[i] == 'u' || s[i] == 'n') {
    int j;
    for (j = i + 1; j < n && s[j] == s[i]; j++) {}
    result = (LL{1} * fib(j - i).sd * result) % kMod;
    i = j;
  }
  else i++;
  cout << result << "\n";
}

int main()
{
  speed_of_cin_and_cout;
  int t = 1;
//   cin >> t;
  while (t--) solve();
  return 0;
}
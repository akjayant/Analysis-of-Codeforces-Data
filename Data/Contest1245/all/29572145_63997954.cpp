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

void solve() {
  int a, b;
  cin >> a >> b;
  cout << (__gcd(a, b) == 1 ? "Finite\n" : "Infinite\n");
}

int main()
{
  speed_of_cin_and_cout;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
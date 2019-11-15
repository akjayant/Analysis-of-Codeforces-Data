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
  int n, r, p, s;
  cin >> n >> r >> p >> s;
  static string b;
  cin >> b;
  static string a;
  a = "";
  int wins = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 'R') {
      if (p > 0) {
        a += "P";
        p--;
        wins++;
      }
      else a += "?";
    } else {
      if (b[i] == 'P') {
        if (s > 0) {
          a += "S";
          s--;
          wins++;
        }
        else a += "?";
      } else {
        if (r > 0) {
          a += "R";
          r--;
          wins++;
        }
        else a += "?";
      }
    }
  }
  if (wins >= (n + 1) / 2) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) if (a[i] == '?') {
      if (r > 0) {
        a[i] = 'R';
        r--;
      } else {
        if (p > 0) {
          a[i] = 'P';
          p--;
        } else {
          a[i] = 'S';
        }
      }
    }
    cout << a << "\n";
  }
  else cout << "NO\n";
    
      
}

int main()
{
  speed_of_cin_and_cout;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
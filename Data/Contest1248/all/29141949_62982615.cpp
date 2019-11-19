// Author: Kamil Nizinski
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(...)
#define cerr if (false) cerr
#define lcl if (false)
#else
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
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
  int even[2] = {0, 0};
  int odd[2] = {0, 0};
  for (int i=0; i<2; i++) {
    int n;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      if (x & 1) odd[i]++;
      else even[i]++;
    }
  }
  LL result = 1ll * even[0] * even[1] + 1ll * odd[0] * odd[1];
  cout << result << "\n";
}
int main()
{
  lcl ios_base::sync_with_stdio(0),cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

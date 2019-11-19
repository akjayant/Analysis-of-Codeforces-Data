#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ff first
#define ss second
#define int long long

using namespace std;

void run(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n;
  int lt = 0;
  int rt = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt++;
      lt = min(lt, i + 1);
      if (lt == 0) lt = i + 1;
      rt = max(rt, i + 1);
    }
  }
  if (cnt == 0) {
    cout << n << '\n';
    return;
  }
  {
    int llt = n - lt + 1;
    int lrt = n - rt + 1;
    cout << max({lt * 2, lrt * 2, rt * 2, llt * 2, n + cnt, rt + rt - lt, lrt + lrt - llt}) << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) run();
  return 0;
}
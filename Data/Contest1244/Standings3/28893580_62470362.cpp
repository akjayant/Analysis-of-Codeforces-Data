#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(v) (v).begin(),v.end()
#define rall(v) (v).rbegin(),v.rend()
#define sz(v) (int)(v).size()
#define ch(c) (c - 'a')

typedef long long ll;
typedef pair<int, int> pi;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    if (count(all(s), '1') == 0) {
      cout << n << endl;
      continue;
    }
    int f = -1, l = -1;
    for (int i = 0; i < n; ++i) {
      if (f == -1 && s[i] == '1')
        f = i;
      if (s[i] == '1')
        l = i;
    }
    cout << max((n - f) * 2, (l + 1) * 2) << endl;
  }
  return 0;
}

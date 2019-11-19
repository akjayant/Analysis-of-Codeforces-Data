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
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = (a + c - 1) / c, y = (b + d - 1) / d;
    if (x + y <= k)
      cout << x << " " << y << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}

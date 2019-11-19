#include <bits/stdc++.h>
#define MAXN 2000
#define pii pair<int,int>
#define pip pair<int,pii>
#define pb push_back
#define ff first
#define ss second
#define int long long
using namespace std;

int n, len, ans, s;
pii pts[MAXN+5];
int c[MAXN+5];
int k[MAXN+5];
int dsu[MAXN+5];
bool vis[MAXN+5];
pip arr[MAXN*MAXN+MAXN+5];
vector <int> pt;
vector <pii> seg;


int dis(int i, int j) {
  return abs(pts[i].ff-pts[j].ff)+abs(pts[i].ss-pts[j].ss);
}

int fnd(int now) {
  if (dsu[now] != now) dsu[now] = fnd(dsu[now]);
  return dsu[now];
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) dsu[i] = i;
  for (int i = 0; i < n; i++) cin >> pts[i].ff >> pts[i].ss;
  for (int i = 0; i < n; i++) cin >> c[i], arr[len++] = pip(c[i],pii(i,i));
  for (int i = 0; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      arr[len++] = pip(dis(i,j)*(k[i]+k[j]),pii(i,j));
    }
  }
  sort(arr, arr+len);
  while (arr[s].ff < 0) s++;
  for (int i = s; i < len; i++) {
    if (vis[fnd(arr[i].ss.ff)] && vis[fnd(arr[i].ss.ss)]) continue;
    if (arr[i].ss.ff == arr[i].ss.ss) {
      ans += arr[i].ff;
      pt.pb(arr[i].ss.ff);
      vis[fnd(arr[i].ss.ff)] = 1;
    } else {
      if (fnd(arr[i].ss.ff) == fnd(arr[i].ss.ss)) continue;
      ans += arr[i].ff;
      seg.pb(pii(arr[i].ss.ff, arr[i].ss.ss));
      if (vis[fnd(arr[i].ss.ff)]) {
        dsu[fnd(arr[i].ss.ss)] = fnd(arr[i].ss.ff);
      } else {
        dsu[fnd(arr[i].ss.ff)] = fnd(arr[i].ss.ss);
      }
    }
    if (pt.size() + seg.size() == n) break;
  }
  cout << ans << '\n';
  cout << pt.size() << '\n';
  for (int i = 0; i < pt.size(); i++) {
    cout << pt[i]+1 << " \n"[i==pt.size()-1];
  }
  cout << seg.size() << '\n';
  for (int i = 0; i < seg.size(); i++) {
    cout << seg[i].ff+1 << ' ' << seg[i].ss+1 << '\n';
  }
  return 0;
}
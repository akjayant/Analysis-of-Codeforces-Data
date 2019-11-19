#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < n; i++)
const int N = 1e5 + 7;
vector<int> E[N];
int c[3][N];
int main() {
#ifdef local
  freopen("in.txt", "r", stdin);
#endif // local
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n; cin >> n;
  for(int o = 0; o < 3; o++){
    for(int i = 1; i <= n; i++) {
      cin >> c[o][i];
    }
  }
  for(int i = 1, u, v; i < n; i++){
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  int rt = 0;
  for(int i = 1; i <= n; i++) {
    if(E[i].size() > 2) return cout << -1 << endl, 0;
    if(E[i].size() == 1) rt = i;
  }
  vector<int> vis(n + 1), rr;
  queue<int> q; q.push(rt); vis[rt] = 1;
  while(!q.empty()) {
    int t = q.front(); q.pop();
    rr.push_back(t);
    for(auto &e : E[t]) if(!vis[e]) q.push(e), vis[e] = 1;
  }

  vector<int> a(3); iota(all(a), 0);
  vector<int> ans; ll aa = LLONG_MAX;
  do {
    ll tmp = 0;
    for(int i = 0; i < n; i += 3){
      for(int j = 0; j < 3 && i + j < n; j++){
        tmp += c[a[j]][rr[i+j]];
      }
    }

    if(tmp < aa) aa = tmp, ans = a;
  } while(next_permutation(all(a)));
  vector<int> va(n + 1);
  cout << aa << endl;
  for(int i = 0; i < n; i += 3) {
    for(int j = 0; j < 3 && i + j < n; j++) {
      //cout << ans[j] + 1 << " \n"[i + j == n - 1];
      va[rr[i + j]] = ans[j] + 1;
    }
  }
  for(int i = 1; i <= n; i++) cout << va[i] << " \n"[i==n];
  return 0;
}

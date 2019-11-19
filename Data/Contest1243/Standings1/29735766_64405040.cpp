#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
map<int, int> qx[N];
int nt[N], fr[N], d[N], vs[N];

void erase(int i) {
  nt[fr[i]] = nt[i];
  fr[nt[i]] = fr[i];
}

queue<int> q;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i) {
    nt[i] = i + 1;
    fr[i] = i - 1;
  }
  nt[0] = 1;
  fr[n + 1] = n;
  for(int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    qx[x][y] = 1, qx[y][x] = 1;
  }
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    if(vs[i]) continue;
    ++res, vs[i] = 1;
    erase(i);
    q.push(i);
    while(!q.empty()) {
      d[res]++;
      int x = q.front(); q.pop();
      for(int j = nt[0]; j != n + 1; j = nt[j]) {
        if(qx[x].count(j)) continue;
        vs[j] = 1, erase(j);
        q.push(j);
      }
    }
  }
  int ans = res-1;
  cout<<ans<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;

long long xs[maxn];
long long ys[maxn];
long long cs[maxn];
long long ks[maxn];
bool used[maxn];
pair<long long, int> dist[maxn][maxn];
int place[maxn][maxn];
int nearest[maxn];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld%lld", &xs[i], &ys[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%lld", &cs[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%lld", &ks[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      long long dis = (ks[i] + ks[j]) * (abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]));
      dist[i][j] = make_pair(dis, j);
      dist[j][i] = make_pair(dis, i);
    }
    dist[i][i] = make_pair(0, i);
  }
  for(int i = 0; i < n; i++) {
    sort(dist[i], dist[i] + n);
    for(int j = 0; j < n; j++) {
      place[i][dist[i][j].second] = j;
    }
  }
  memset(nearest, -1, sizeof nearest);
  long long acost = 0;
  vector<int> pss;
  vector<pair<int, int>> ess;
  for(int i = 0; i < n; i++) {
    long long mincost = LLONG_MAX;
    int mincostp = 0;
    int mincostg = 0;
    for(int j = 0; j < n; j++) {

      if(used[j]) continue;

      // j to be generato]r
      long long cost = cs[j];
      int costp = j;
      int costg = -1;
      if(nearest[j] != -1) {
        if(dist[j][nearest[j]].first < cost) {
          cost = dist[j][nearest[j]].first;
          costg = dist[j][nearest[j]].second;
        }
      }
      if(cost < mincost) {
        mincost = cost;
        mincostp = costp;
        mincostg = costg;
      }
    }
    used[mincostp] = true;
    acost += mincost;
    if(mincostg == -1) {
      pss.push_back(mincostp);
    } else {
      ess.push_back(make_pair(mincostp, mincostg));
    }
    for(int j = 0; j < n; j++) {
      if(nearest[j] == -1) nearest[j] = place[j][mincostp];
      nearest[j] = min(nearest[j], place[j][mincostp]);
    }
  }
  printf("%lld\n", acost);
  printf("%d\n", (int)pss.size());
  for(auto i: pss) {
    printf("%d ", i + 1);
  }
  puts("");
  printf("%d\n", (int)ess.size());
  for(auto &p: ess) {
    printf("%d %d\n", p.first + 1, p.second + 1);
  }
  return 0;
}

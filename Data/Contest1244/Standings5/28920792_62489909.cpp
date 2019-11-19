#include <bits/stdc++.h>
 
using namespace std;
using LL = long long int; 

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}
 
template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

const int MAXN = 1e5 + 5;
int n;
vector<int> G[MAXN];
LL cost[4][1000005];
int res[MAXN];
LL cnt = 0;
int printt[MAXN];

void ustaw() {
  for (int i= 1; i <= n; ++i) {
    printt[i] = res[i];
  }
}

void dfs(int w, int o, int myColor, int next) {
  res[w] = myColor;
  cnt += cost[myColor][w];

  set<int> s = {1, 2, 3};
  s.erase(myColor);
  s.erase(next);
  int nextt = *(s.begin());

  for (auto u : G[w]) {
    if (u != o) {
      dfs(u, w, next, nextt);
    }
  }
}
LL best = 1 << 30;
int main() {
  best *= best;
  cin >> n;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> cost[i][j];
    }
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    if (G[a].size() >= 3 || G[b].size() >= 3) {
      // cout << "SDADS " << G[b].size() << endl;
      cout << -1;
      return 0;
    }
  }

  int start;
  for (int i = 1; i <= n; ++i) {
    if (G[i].size() == 1) {
      start = i;
      break;
    }
  }

  dfs(start, 0, 1, 2);
  best = cnt;
  ustaw();

  cnt = 0;  
  dfs(start, 0, 1, 3);
  if (cnt < best) {
    best = cnt;
    ustaw();
  }
  
  cnt = 0;
  dfs(start, 0, 2, 1);
  if (cnt < best) {
    best = cnt;
    ustaw();
  }
  
  cnt = 0;
  dfs(start, 0, 2, 3);
  if (cnt < best) {
    best = cnt;
    ustaw();
  }
  
  cnt = 0;
  dfs(start, 0, 3, 1);
  if (cnt < best) {
    best = cnt;
    ustaw();
  }
  
  cnt = 0;
  dfs(start, 0, 3, 2);
  if (cnt < best) {
    best = cnt;
    ustaw();
  }

  cout << best << endl;
  for (int i =1; i <= n; ++i) {
    cout << printt[i] << " ";
  }
}
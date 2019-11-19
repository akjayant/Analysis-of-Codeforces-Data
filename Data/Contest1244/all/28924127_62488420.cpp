#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define double long double
#define fo(i, n)    for(int i = 0; i < n; i ++)
#define foe(i, n)   for(int i = 0; i <= n; i ++)
#define fo1(i, n)   for(int i = 1; i < n; i ++)
#define fo1e(i, n)  for(int i = 1; i <= n; i ++)
using namespace std;

vector<int> g[105000];
int c[105000][3];
int v_clr[105000];
int sum = 0;
bool global = true;

void check(int v, int p){
  if(g[v].size() > 2)
    global = false;
  for(int x: g[v]){
    if(x != p)
      check(x, v);
  }
}

void color(int v, int p, int cp, int cpp){
  int clr;
  for(int i = 0; i < 3; i ++){
    if(i != cp && i != cpp){
      sum += c[v][i];
      clr = i;
      break;
    }
  }
  for(int x: g[v]){
    if(x != p){
      color(x, v, clr, cp);
    }
  }
}

void f(int v, int p, int c1, int c2){
  int clr;
  fo(i, 3){
    if(i != c1 && i != c2){
      clr = i;
      break;
    }
  }
  v_clr[v] = clr + 1;
  for(int x: g[v]){
    if(x != p){
      f(x, v, clr, c1);
    }
  }
}

int32_t main(){
  int n; cin >> n;
  fo(i, n)
    cin >> c[i][0];
  fo(i, n)
    cin >> c[i][1];
  fo(i, n)
    cin >> c[i][2];
  map<int, int> cnt;
  fo(i, n-1){
    int u, v; cin >> u >> v;
    g[u-1].pb(v-1);
    g[v-1].pb(u-1);
    cnt[u-1] ++;
    cnt[v-1] ++;
  }
  int s = 0;
  for(auto x: cnt)
    if(x.S == 1)
      s = x.F;
  check(s, -1);
  if(!global){
    cout << -1;
    return 0;
  }
  int c1, c2;
  int ans = 1e18 + 228;
  for(int i = 0; i < 3; i ++){
    for(int j = 0; j < 3; j ++){
      if(i != j){
        sum = 0;
        color(s, -1, i, j);
        if(sum < ans){
          ans = sum;
          c1 = i;
          c2 = j;
        }
      }
    }
  }
  cout << ans << endl;
  f(s, -1, c1, c2);
  fo(i, n)
    cout << v_clr[i] << " ";

}

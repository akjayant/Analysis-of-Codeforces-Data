#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vl vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

vvl C = vv(3, 100001, 0, ll);
vvl G = vv(100001, 0, 0, ll);
ll INF = 100000000000000000;
ll ans = INF;
vector<ll> ans_color(100001, -1);
vector<ll> tmp_color(100001, -1);
ll dfs(ll now, ll from, ll mode){
  ll tmp = 0;
  tmp += C[mode][now];
  tmp_color[now] = mode;
  mode = (mode+1)%3;
  for(int i=0;i<G[now].size();i++){
    if(G[now][i]==from) continue;
    tmp += dfs(G[now][i], now, mode);
  }
  return tmp;
}
ll dfs2(ll now, ll from, ll mode){
  ll tmp = 0;
  tmp += C[mode][now];
  tmp_color[now] = mode;
  mode = (mode+2)%3;
  for(int i=0;i<G[now].size();i++){
    if(G[now][i]==from) continue;
    tmp += dfs2(G[now][i], now, mode);
  }
  return tmp;
}
int main(int argc, char const *argv[]) {
  ll N, a, b;
  std::cin >> N;
  for(int i=0;i<3;i++) for(int j=1;j<=N;j++) std::cin >> C[i][j];
  for(int i=0;i<N-1;i++){
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll st = -1, c = 0;
  for(int i=1;i<=N;i++){
    if(G[i].size()==1){
      st = i;
      c++;
    }
  }
  if(c>=3){
    std::cout << -1 << '\n';
    return 0;
  }

  for(int i=0;i<3;i++){
    ll A = dfs(st, -1, i);
    if(A <= ans) {
      ans = A;
      for(int j=1;j<=N;j++) ans_color[j] = tmp_color[j];
    }
  }
  for(int i=0;i<3;i++){
    ll A = dfs2(st, -1, i);
    if(A <= ans) {
      ans = A;
      for(int j=1;j<=N;j++) ans_color[j] = tmp_color[j];
    }
  }
  std::cout << ans << '\n';
  for(int i=1;i<=N;i++) std::cout << ans_color[i]+1 << (i==N?"\n":" ");
  return 0;
}

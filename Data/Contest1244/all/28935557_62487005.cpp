#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
#define all(c) (c).begin(),(c).end()
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const ll MOD = 1e9+7;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"[";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"]";return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&p)
{o<<"{"<<p.first<<", "<<p.second<<"}";return o;}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj)
{o<<"{";for(auto itr=obj.begin();itr!=obj.end();++itr)o<<(itr!=obj.begin()?", ":"")<<*itr;o<<"}";return o;}
void dump() {}
template <class H, class... T>void dump(H&& head, T&&... tail)
{cout << head << (sizeof...(tail)==0 ? "\n" : " "); dump(forward<T>(tail)...);}

vector<int> color;
vector<vector<int>> G;

void dfs(int v, int p){
  int c;
  
  if(color[p] == 0){
    c = 1;
  }else if(color[p] == 1){
    c = 2;
  }else{
    c = 0;
  }
  color[v] = c;
  for(auto u : G[v]){
    if(u != p) dfs(u,v);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<vector<int>> cost(3,vector<int>(n,0));
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < n; ++j){
      cin >> cost[i][j];
    }
  }

  G.assign(n,vector<int>());

  for(int i = 0; i < n-1; ++i){
    int u,v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  color.assign(n,-1);
  int st;
  for(int i = 0; i < n; ++i){
    if(G[i].size() >= 3){
      cout << -1 << endl;
      exit(0);
    }else if(G[i].size() == 1){
      st = i;
    }
  }
  color[st] = 0;

  dfs(G[st][0], st);
//dump(G,st,color);
  ll ans = LINF;
  vector<int> rplCol = {0,1,2};
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      for(int k = 0; k < 3; ++k){
        if(i==j || j==k || k==i) continue;
        vector<int> rpl = {i,j,k};
        ll newAns = 0;
        for(int m = 0; m < n; ++m){
          newAns += cost[rpl[color[m]]][m];
        }
        if(ans > newAns){
          ans = newAns;
          rplCol = rpl;
        }
      }
    }
  }
  cout << ans << endl;
  for(int i = 0; i < n; ++i){
    cout << rplCol[color[i]]+1;
    cout << (i==n-1 ? "\n" : " ");
  }
  return 0;
}

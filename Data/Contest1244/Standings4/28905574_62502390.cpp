#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

long long dfs(const vector<vector<int>> &G, int v, int p, const vector<vector<int>> &C, const vector<int> &P, vector<int> &A, int d){
  A[v] = P[d%3];
  long long ret = C[P[d%3]][v];
  for(auto v_ : G[v]){
    if(v_ == p) continue;
    ret += dfs(G,v_,v,C,P,A,d+1);
  }
  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> C(3,vector<int>(n));
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < n; ++j){
      cin >> C[i][j];
    }
  }
  vector<vector<int>> G(n);
  for(int i = 1; i < n; ++i){
    int u, v;
    cin >> u >> v;
    --u,--v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int s = -1;
  for(int i = 0; i < n; ++i){
    if(G[i].size() == 1){
      s = i;
    }
    if(G[i].size() > 2){
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> P = {0,1,2};
  vector<int> A(n,-1);
  long long S = 1e18;
  do{
    vector<int> A_(n,-1);
    long long S_ = dfs(G,s,-1,C,P,A_,0);
    if(S_ < S){
      S = S_;
      swap(A,A_);
    }
  }while(next_permutation(P.begin(), P.end()));
  cout << S << endl;
  for(auto a : A){
    cout << a+1 << " ";
  }
  cout << endl;
}

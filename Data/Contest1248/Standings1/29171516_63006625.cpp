#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e6+10 ;
bool mark[maxn] ;
vector<int> adj[maxn] ;
vector<int> adj2[maxn];

int lol ;

void dfs(int u){

  lol++ ;
  mark[u] = 1 ;
  for(auto v: adj[u]){

    if(!mark[v])
      dfs(v) ;

  }

}

void dfs2(int u){

  lol++ ;
  mark[u] = 0 ;
  for(auto v: adj2[u]){

    if(mark[v])
      dfs2(v) ;

  }

}

int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  int T ;
  cin >> T ;
  for(int t = 0; t < T; t++){

    int n, m ;
    cin >> n >> m ;
    for(int i = 0; i < n; i++){
      adj[i].clear() ;
      adj2[i].clear();
      mark[i] = 0 ;
    }
    for(int i = 0; i < m; i++){

      int u, v ;
      cin >> u >> v ;
      u-- ;
      v-- ;
      adj[v].push_back(u) ;
      adj2[u].push_back(v);

    }
    lol = 0 ;
    dfs(0) ;

    if(lol == n){

      lol = 0 ;
      dfs2(0) ;
      if(lol == n){

        cout << "NO\n" ;
        continue ;

      }
      lol = n-lol ;

    }
    cout <<"YES\n"<< n-lol <<' '<< lol << '\n' ;
    for(int i = 0; i < n; i++){

      if(!mark[i])
        cout << i+1 << ' ' ;

    }
    cout << '\n' ;
    for(int i = 0; i < n; i++){

      if(mark[i])
        cout << i+1 << ' ' ;

    }
    cout << '\n' ;

  }

}

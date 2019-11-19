// a nu cheeki reeki i v damke !

#include<bits/stdc++.h>
using namespace std ;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define F first
#define S second

const long long maxn = 1e5+10 ;
set<int> notadj[maxn] ;
set<int> nosee ;
bool mark[maxn] ;

void dfs(int u){

  mark[u]=1 ;
  vector<int> dam ;
  for(auto it = nosee.begin(); nosee.size()>0 && it != nosee.end(); it++){

    //cout << *it << endl ;
    if(notadj[u].find(*it) == notadj[u].end()){

      dam.push_back(*it) ;

    }

  }
  for(auto v:dam)
    nosee.erase(v) ;
  for(auto v:dam)
    dfs(v) ;

}

int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  long long n, m ;
  cin >> n >> m ;
  for(int i = 0; i < n; i++){

    nosee.insert(i) ;

  }
  for(int i = 0; i < m; i++){

    int u, v ;
    cin >> u >> v ;
    u-- ;
    v-- ;
    notadj[u].insert(v) ;
    notadj[v].insert(u) ;

  }
  int ans = 0  ;
  for(int i = 0; i < n ; i++){

    if(!mark[i]){
      nosee.erase(i) ;
      ans++ ;
      dfs(i) ;
    }

  }
  cout << ans-1 ;

}

//In the name of Allah
//Ya Ali!
#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

const ll maxn = 1000 * 101 ;
const ll INF = 1e18 ;

#define f first
#define s second

ll n , m , mark[maxn] ;
vector<ll> g[maxn] , mo[maxn] ;
set<pair<ll,ll> > ve ;
set<pair<ll,ll> > :: iterator it ;
vector<pair<ll,ll> > ea ;

void del(){

  while(ea.size()){
    pair<ll,ll> p = ea.back() ;
    it = ve.find(p) ;
    ve.erase(it) ;
    ea.pop_back() ;
  }

}

bool ch(ll v , ll u){
 ll x = lower_bound(g[u].begin() , g[u].end() , v) - g[u].begin() ;

 if(x >= g[u].size() || x < 0)return false ;

 else if(g[u][x] != v)return false ;

 else return true ;
}

void solve(ll v, ll ind){

 mo[ind].push_back(v) ;
 mark[v] = 1 ;

 ve.erase({g[v].size() , v}) ;

 queue<ll> qu ;

 for(it = ve.begin() ; it != ve.end() ; it ++){
    ll u = (*it).s ;
    if(!ch(v , u)){
        //cout << v << " " << u << " " << ch(v ,u) << endl ;
        qu.push(u) ;
        mo[ind].push_back(u) ;
        mark[u] = 1 ;
        ea.push_back({(*it).f , (*it).s}) ;
    }
 }

 del() ;

 while(qu.size()){

    ll p = qu.front() ;
    qu.pop() ;

    for(it = ve.begin() ; it != ve.end() ; it ++){
        ll u = (*it).s ;
        if(!ch(p , u) && mark[u] == 0){
            mark[u] = 1 ;
            qu.push(u) ;
            mo[ind].push_back(u) ;
            ea.push_back({(*it).f , (*it).s}) ;
        }
    }

    del() ;
 }

}

int main()
{
std::ios::sync_with_stdio(0) ;
cin.tie(0) ;
cout.tie(0) ;

cin >> n >> m ;
for(int i = 0 ; i < m ; i ++){

    ll v , u ;
    cin >> v >> u ;
    g[v].push_back(u) ;
    g[u].push_back(v) ;
}

for(int i = 1 ; i <= n ; i ++)sort(g[i].begin() , g[i].end()) ;

for(int i = 1 ; i <= n ; i ++)ve.insert({g[i].size() , i}) ;

ll ind = 0 ;
while(ve.size()){
    it = ve.begin() ;
    ll v = (*it).s ;
    if(!mark[v]){
      ind ++ ;
      solve(v , ind) ;
    }
}

cout << ind-1 << "\n" ;

 return 0;
}
/*
                  _     _   __
            /_\  (_    (_)  __)
           /   \  _) . (_) (__
*/

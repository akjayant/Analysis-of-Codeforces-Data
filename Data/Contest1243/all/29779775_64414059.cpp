/*input
3 0
*/
/**
    Author: Kristopher Paul
    Date Created: 06-11-2019
    Contest Name:
                _/    _/   _/_/_/_/   _/   _/_/_/_/
               _/  _/     _/    _/   _/   _/
              _/_/       _/_/_/_/   _/   _/_/_/_/
             _/  _/     _/  _/     _/         _/
            _/    _/   _/    _/   _/   _/_/_/_/
**/
#include<bits/stdc++.h>
#include<stdio.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int ll
#define pb push_back
#define INF 1e18
#define MOD 1000000007
//#define MOD 998244353
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define umap unordered_map
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define out(x) cout << #x << " is " << x << endl
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // set
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // multiset

int ModExp(int x,int y,int m){
    int res = 1;
    x = x % m;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % m;

        y = y>>1;
        x = (x*x) % m;
    }
    return res;
}

set<int> vis;
set<pii> adj;
 
int con[200005];
int ans = 0;

void dfs(int n){ 
    vis.erase(n);
    con[n] = ans;
    auto it = vis.begin();
    int v = -1;
    while(it != vis.end()){
        int u = (*it);
        if(adj.find(make_pair(u,n)) != adj.end() || adj.find(make_pair(n,u)) != adj.end()){
            it++;
        }else{
            v = u;
            dfs(u);
            it = vis.lower_bound(u);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    FOR(i,0,m){
        int u,v;
        cin >> u >> v;
        adj.insert(mp(u, v));
        adj.insert(mp(v, u));
    }
    FOR(i,1,n+1){
        vis.insert(i);
    }
    FOR(i,1,n+1){
        if(vis.find(i) != vis.end()){
            ans++;
            dfs(i);
        }
    }
    cout << ans-1 << endl;
}

signed main(){
    FastIO;
    int t = 1;
//    cin >> t;
    WL(t){
        solve();
    }
}

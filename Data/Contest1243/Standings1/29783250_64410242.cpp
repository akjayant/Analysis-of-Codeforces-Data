//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N], vis[N];

set<ll> req;
map<ll, ll> mp[N];

void solve(){
    ll n, m, x, y;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        mp[x][y] = 1;
        mp[y][x] = 1;
    }
    for(int i = 1; i <= n; ++i){
        req.insert(i);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ++res;
            req.erase(i);
            queue<ll> q;
            q.push(i);
            while(!q.empty()){
                ll node = q.front();
                q.pop();
                vector<ll> temp;
                for(auto j: req){
                    if(!mp[node].count(j)){
                        temp.push_back(j);
                        q.push(j);
                        vis[j] = 1;
                    }   
                }
                for(auto j: temp){
                    req.erase(j);
                }
            }
        }
    }
    cout << res - 1;
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
// nEro
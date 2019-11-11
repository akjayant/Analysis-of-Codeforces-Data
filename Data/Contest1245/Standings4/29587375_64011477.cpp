//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];

inline ll add(ll x, ll y){  return  (x % mod + y % mod) % mod;}
inline ll sub(ll x, ll y){  return  (x % mod - y % mod + mod) % mod;}
inline ll mul(ll x, ll y){  x %= mod;   y %= mod;   return 1LL * x * y % mod;}

void solve(){
    ll fl = 1;
    res = 1;
    string s;
    cin >> s;
    a[1] = 1;
    a[2] = 2;
    for(int i = 3; i < N; ++i){
        a[i] = add(a[i - 1], a[i - 2]); 
    }
    for(int i = 0; i < s.size(); ++i){
        ll cur = 0;
        if(s[i] == 'm' or s[i] == 'w')    fl = 0;
        while(i < s.size() and s[i] == 'u'){
            ++cur;
            ++i;
        }
        if(cur) res = mul(res, a[cur]), --i;
        cur = 0;
        while(i < s.size() and s[i] == 'n'){
            ++cur;
            ++i;
        }
        if(cur) res = mul(res, a[cur]), --i;
    }
    cout << res * fl << "\n";
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
//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];

void solve(){
    ll n;
    cin >> n;
    ll val = n;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            val = __gcd(val, i);
            val = __gcd(val, n / i);
        }
    }
    cout << val << "\n";
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
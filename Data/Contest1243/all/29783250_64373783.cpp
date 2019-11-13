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
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 1000; i >= 0; --i){
        ll cur = 0;
        for(int j = 0; j < n; ++j){
            cur += (a[j] >= i);
        }
        if(cur >= i){
            cout << i << "\n";
            return;
        }
    }
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
// nEro
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " " << x << endl

int v[200005];
ll mod = 1e9+7;
ll modpow(ll b, ll e){
    if(e == 0) return 1LL;
    if(b == 0) return 1LL;
    if(e == 1) return (b%mod);
    ll res = modpow(b, e/2);
    res = (res*res)%mod;
    if(e%2 == 1)
        res = (res * (b%mod))%mod;
    return res;
}

int main(){
	
    cout.sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    ll aux = (modpow(2, m) - 1 + mod)%mod;
    ll res = modpow(aux, n);
    cout << res << endl;
	return 0;
}

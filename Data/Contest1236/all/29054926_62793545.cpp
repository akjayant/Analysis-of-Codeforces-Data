#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}
ll sub(ll a, ll b){
    return((a % MOD - b % MOD + MOD) % MOD);
}
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	cout << power(sub(power(2, m), 1), n);
}
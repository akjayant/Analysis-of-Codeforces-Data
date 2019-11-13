#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define zak ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e3 + 5, M = 1e5 + 5, mod = 1e9 + 7;

ll modPow(ll b, ll p){
    if(!p) return 1;
    ll halfPow = modPow(b, (p >> 1)) % mod;
    halfPow = ((halfPow%mod)*(halfPow%mod))%mod;
    if(p & 1) halfPow = ((halfPow%mod) * (b%mod))%mod;
    return halfPow % mod;
}


int main(){
    zak
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll ret = modPow(2ll, m) - 1;
    ret = (ret + mod) % mod;
    ret = modPow(ret, n);
    printf("%lld", ret);
}

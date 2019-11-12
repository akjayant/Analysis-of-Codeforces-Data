#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
//a^n (mod m)
const long long mod = 1e9+7;
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//mod m�ł� a �̋t�������߂�
long long modinv(long long a) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod; 
    if (u < 0) u += mod;
    return u;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    
    ll n,m;
    cin>>n>>m;
    ll ans = modpow(2,m);
    ans = modpow((ans+mod-1)%mod,n);
    cout << ans << endl;

    
    
}
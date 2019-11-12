#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1.0);
#define eps 10e-8
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll inverse(ll a) { return a == ll(1) ? ll(1) : (mod - mod / a) * inverse(mod % a) % mod; } // 求逆元
const int MAXN = 1e6 + 5;
const int MAXM = 2 * MAXN;
const int INF = 0x3f3f3f3f;
//clock_t c1 = clock(); //测时间
//std::cerr << "Time:" << clock() - c1 <<"ms" << std::endl;
//=======================================================================//
ll pow_mod(ll a, ll b) {
    ll res = 1;
    for(; b; b >>= 1) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
int main(){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll ans=pow_mod(2,k)-1;
        ans=pow_mod(ans,n);
        printf("%lld\n",ans);   
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//{
    #ifdef lawfung
    #define debug(...) do {\
        fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
        _DO(__VA_ARGS__);\
    }while(0)
    template<typename I> void _DO(I&&x) {cerr << x << '\n';}
    template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
    #define IOS
    #else
    #define debug(...)
    #define IOS ios_base::sync_with_stdio(0);cin.tie(0)
    #endif
    typedef long long ll;
    typedef pair<int,int> pii;
    typedef pair<ll,ll> pll;
    typedef pair<double,double> pdd;
    typedef long double ld;
    #define F first
    #define S second
    #define ALL(x)  (x).begin(),(x).end()
    #define SZ(x)   (ll)x.size()
    #define pb push_back
    #define eb emplace_back
    #define stp setprecision(30)<<fixed
    const int NF = 0x3f3f3f3f;
    const ll INF = 0x3f3f3f3f3f3f3f3f;
    const ll MO7 = 1e9 + 7;
    const ll MO9 = 1e9 + 9;
    const ll MO87 = 1e9 + 87;
    const ll MO93 = 1e9 + 93;
    const ll MO53 = 998244353;
    const ld PI = 3.14159265358979323846264338327950288;
    const ld eps = 1e-7;
//}
const ll MAX = 2e5 + 6, Mlg = __lg(MAX) + 2;
ll n, m;
ll power(ll a, ll b, ll mod) {
    if(b == 0)  return 1;
    return power(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
int main() {
    IOS;
    cin >> n >> m;
    ll tmp = power(2, m, MO7);
    -- tmp;
    if(tmp < 0)
        tmp += MO7;
    tmp = power(tmp, n, MO7);
    cout << tmp << '\n';
    return 0;
}

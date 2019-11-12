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
ll n;
int pro(int a, int b, int c) {
    int ans = 0;
    for(int i = 0; i <= a; ++ i) {
        if(b < i + i)   continue;
        int tmp = i * 3;
        int bb = b - i - i;
        int m = min(bb, c / 2);
        tmp += m * 3;
        ans = max(ans, tmp);
    }
    return ans;
} 
int main() {
    IOS;
    int t;
    cin >> t;
    while(t --) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << pro(a, b, c) << '\n';
    }
    return 0;
}

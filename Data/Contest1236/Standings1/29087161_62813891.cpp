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
const ll MAX = 2e5 + 6, Mlg = __lg(MAX) + 2, M = 1e5 + 3;
ll n, m;
ll arr[MAX];
int fa[MAX];
int vvv[MAX];
ll val[MAX];
/*
int anc[MAX][Mlg];
void build() {
    for(int i = 1; i <= m; ++ i)
        anc[i][0] = fa[i];
    for(int j = 1; j < Mlg; ++ j) {
        for(int i = 1; i <= m; ++ i) {
            anc[i][j] = anc[ans[i][j - 1]][j - 1];
        }
    }
    return;
}
*/
ll pro() {
    memset(vvv ,0, sizeof vvv);
    for(int i = m; i; -- i) {
        ll x = arr[i] - i;
        fa[i] = vvv[x - 1 + M];
        if(fa[i])
            val[i] = val[fa[i]];
        else
            val[i] = min(arr[i] + (m - i), n);
        vvv[x + M] = i;
    }
    //build();
    ll rt = 0;
    debug(rt);
    for(int i = 1; i <= n; ++ i) {
        ll x = i;
        x = vvv[x + M];
        if(x)
            rt += (val[x] - i + 1);
        else
            rt += (min(n, i + (m + 1)) - i + 1);
        debug(i, rt);
    }
    return rt;
}
int main() {
    IOS;
    cin >> n >> m;
    for(int i = 1; i <= m; ++ i){
        cin >> arr[i];
    }
    if(n == 1) {
        cout << "0\n";
        return 0;
    }
    ll ans = 0;
    ans += pro();
    debug(ans);
    for(int i = 1; i <= m; ++ i) {
        arr[i] = n - arr[i] + 1;
    }
    ans += pro();
    cout << ans - n << '\n';
    return 0;
}

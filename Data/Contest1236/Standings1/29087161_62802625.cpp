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
ll n, m, k;
map<int, int> mp[MAX], pm[MAX];
int che(int x1, int x2, int y1, int y2, int d) {
    if(x1 > x2 || y1 > y2)  return 1;
    if(d == 1) {
        int mi = y2 + 1;
        for(auto i : mp[x1]) {
            mi = min(mi, i.F);
        }
        for(int y = mi; y <= y2; ++ y) {
            for(int x = x1; x <= x2; ++ x) {
                if(mp[x].find(y) == mp[x].end() ){
                    return 0;
                }
                mp[x].erase(y);
                pm[y].erase(x);
            }
        }
        ++ x1;
        y2 = mi - 1;
        return che(x1, x2, y1, y2, 2);
    }
    if(d == 2) {
        int mi = x2 + 1;
        for(auto i : pm[y2]) {
            mi = min(mi, i.F);
        }
            for(int x = mi; x <= x2; ++ x) {
        for(int y = y1; y <= y2; ++ y) {
                if(mp[x].find(y) == mp[x].end() ){
                    return 0;
                }
                mp[x].erase(y);
                pm[y].erase(x);
            }
        }
        -- y2;
        x2 = mi - 1;
        return che(x1, x2, y1, y2, 3);
    }
    if(d == 3) {
        int ma = y1 - 1;
        for(auto i : mp[x2]) {
            ma = max(ma, i.F);
        }
        for(int y = y1; y <= ma; ++ y) {
            for(int x = x1; x <= x2; ++ x) {
                if(mp[x].find(y) == mp[x].end() ){
                    return 0;
                }
                mp[x].erase(y);
                pm[y].erase(x); 
            }
        }
        -- x2;
        y1 = ma + 1;
        return che(x1, x2, y1, y2, 4);
    }
    if(d == 4) {
        int ma = x1 - 1;
        for(auto i : pm[y1]) {
            ma = max(ma, i.F);
        }
            for(int x = x1; x <= ma; ++ x) {  
        for(int y = y1 ; y <= y2; ++ y) {
                if(mp[x].find(y) == mp[x].end() ){
                    return 0;
                }
                mp[x].erase(y);
                pm[y].erase(x);
            }
        }
        ++ y1;
        x1 = ma + 1;
        return che(x1, x2, y1, y2, 1);
    }
    assert(0);
}
int main() {
    IOS;
    cin >> n >> m >> k;
    while(k --) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
        pm[y][x] = 1;
    }
    if(che(1, n, 1, m, 1)) {
        cout << "Yes\n";
    }
    else
        cout << "No\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// macros
#define overload_rep(_1, _2 ,_3 ,name, ...) name
#define re_p(i, n) for(int i = 0; i < (n); ++i)
#define r_ep(i, x, y) for(int i = (x); i <= (y); ++i)
#define rep(...) overload_rep(__VA_ARGS__, r_ep, re_p)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#ifndef STOP_DEBUG
#define debug(...)\
    do { cerr << boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_cerr(__VA_ARGS__); cerr << noboolalpha; } while (0)
#else
#define debug(...)
#endif

// functions
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
void debug_cerr(){ cerr << '\n'; }
template<class Head, class... Tail>
void debug_cerr(Head head, Tail... tail){
    cerr << ' ' << head;
    debug_cerr(tail...);
}

// cin/cout setup
struct IoSetup{
    IoSetup(){
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} iosetup;

// Codeforces Round #594 (Div. 2)

void solve(){
    int n;
    cin >> n;
    int o1 = 0, e1 = 0;
    rep(i, n){
        int p;
        cin >> p;
        if(p & 1)o1++;
        else e1++;
    }
    int m;
    cin >> m;
    int o2 = 0, e2 = 0;
    rep(i, m){
        int q;
        cin >> q;
        if(q & 1)o2++;
        else e2++;
    }
    cout << (long long)e1 * e2 + (long long)o1 * o2 << '\n';
}

int main(){
    
    int T;
    cin >> T;
    rep(i, T)solve();

}
#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define INF  (1<<30)
#define INFL (1LL<<60)
#define EPS ((ld)(1e-9))
 
#define sz(x) ((int)(x).size())
#define setz(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define rep(i, e) for (int i = 0, _##i = (e); i < _##i; i++)
#define repp(i, s, e) for (int i = (s), _##i = (e); i < _##i; i++)
#define repr(i, s, e) for (int i = (s)-1, _##i = (e); i >= _##i; i--)
#define repi(i, x) for (auto &i : (x))
#define ARR(...) vector<int>({__VA_ARGS__})
#define ARS(...) vector<string>({__VA_ARGS__})
 
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> base;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) { 
    return os << '(' << pai.first << ' ' << pai.second << ')';
}
 
template<typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    cout << '[';
    for (auto p : v) cout << p << ",";
    cout << "]";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const set<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
#ifndef __DJKIM613
#define debug(...) 0
#define endl '\n'
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cout << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cout << *sdbg++;
    cout << '=' << (h) << ','; 
    _dbg(sdbg+1, a...);
}
#endif
 
template<typename T> void get_max(T &a, T b) {a = max(a, b);}
template<typename T> void get_min(T &a, T b) {a = min(a, b);}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

typedef long long ll;
const int MAXN = 1e5 + 10;

ll N, M, K;
ll U, D, L, R;

ll cnt = 1;
set<ll> X[MAXN];
set<ll> Y[MAXN];

typedef pair<int, pii> tpi;
set<tpi> ck;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;
    for(int i = 0 ; i < K ; i++) {
        ll x, y;
        cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }

    D = N + 1;   R = M + 1;

    int dir = 0, x = 1, y = 1;

    for(int i = 1 ; i <= N ; i++) X[i].insert(M + 1), X[i].insert(0);
    for(int i = 1 ; i <= M ; i++) Y[i].insert(N + 1), Y[i].insert(0);

    int is_start = 1;
    while(1){
        int ndir = (dir + 1) % 4;
        ck.insert(tpi(dir, pii(x, y)));
        //cout << x << ' ' << y << '\n';
        assert(1 <= x && x <= N && 1 <= y && y <= M);
        if(dir == 0){
            ll nxty = *X[x].lower_bound(y);
            if(nxty > R) nxty = R;
            nxty--;
            if(!is_start && y == nxty) break;
            U = x;
            cnt += nxty - y;
            y = nxty;
        }
        else if(dir == 1){
            ll nxtx = *Y[y].lower_bound(x);
            if(nxtx > D) nxtx = D;
            nxtx--;
            if(!is_start && x == nxtx) break;
            R = y;
            cnt += nxtx - x;
            x = nxtx;
        }
        else if(dir == 2){
            ll nxty = *(--X[x].upper_bound(y));
            if(nxty < L) nxty = L;
            nxty++;
            if(!is_start && y == nxty) break;
            D = x;
            cnt += y - nxty;
            y = nxty;
        }
        else{
            ll nxtx = *(--Y[y].upper_bound(x));
            if(nxtx < U) nxtx = U;
            nxtx++;
            if(!is_start && x == nxtx) break;
            L = y;
            cnt += x - nxtx;
            x = nxtx;
        }
        dir = (dir + 1) % 4;
        is_start = 0;
    }

    if(cnt == N * M - K) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
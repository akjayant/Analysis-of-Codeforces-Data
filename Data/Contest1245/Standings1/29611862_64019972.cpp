#define INTERACTIVE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // gp_hash_table<int, int> == hash map
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using max_heap = priority_queue<T, vector<T>, less<T>>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename K, typename V> using hashmap = gp_hash_table<K, V>;

template<typename A, typename B> ostream& operator<<(ostream& out, pair<A, B> p) { out << "(" << p.first << ", " << p.second << ")"; return out;}
template<typename T> ostream& operator<<(ostream& out, vector<T> v) { out << "["; for(auto& x : v) out << x << ", "; out << "]";return out;}
template<typename T> ostream& operator<<(ostream& out, deque<T> v) { out << "["; for(auto& x : v) out << x << ", "; out << "]";return out;}
template<typename T> ostream& operator<<(ostream& out, set<T> v) { out << "{"; for(auto& x : v) out << x << ", "; out << "}"; return out; }
template<typename K, typename V> ostream& operator<<(ostream& out, map<K, V> m) { out << "{"; for(auto& e : m) out << e.first << " -> " << e.second << ", "; out << "}"; return out; }
template<typename K, typename V> ostream& operator<<(ostream& out, hashmap<K, V> m) { out << "{"; for(auto& e : m) out << e.first << " -> " << e.second << ", "; out << "}"; return out; }

template<typename T> T read() {T x;cin >> x;return x;}
template<typename T> vector<T> read(int n) {vector<T> v(n);for(auto& x : v) cin >> x;return v;}
template<typename A, typename B>istream& operator>>(istream& in, pair<A, B>& p) {return in >> p.first >> p.second;}

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define TESTS(t) int NUMBER_OF_TESTS; cin >> NUMBER_OF_TESTS; for(int t = 1; t <= NUMBER_OF_TESTS; t++)
#define FOR(i, begin, end) for (int i = (begin); i < (end); i++)
#define sgn(a)     ((a) > eps ? 1 : ((a) < -eps ? -1 : 0))
#define precise(x) fixed << setprecision(x)
#define all(a) a.begin(), a.end()
#define pb push_back
#define rnd(a, b) (uniform_int_distribution<int>((a), (b))(rng))
#ifndef LOCAL
    #define cerr if(0)cout
    #ifndef INTERACTIVE
        #define endl "\n"
    #endif
    #define debug(args...) if(0){}
#else
    #define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); dbg(_it, true, args); }
    void dbg(istream_iterator<string> it, bool isStart) {cerr << "</debug>" << endl;}
    template<typename T, typename... Args>
    void dbg(istream_iterator<string> it, bool isStart, T a, Args... args) {
        if(isStart) cerr << "<debug>" << endl;
        cerr << "  " << *it << " = " << a << endl;
        dbg(++it, false, args...);
    }
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
std::chrono::steady_clock::time_point __clock__;
void startTime() {__clock__ = std::chrono::steady_clock::now();}
ld getTime() {
    auto end = std::chrono::steady_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::microseconds> (end-__clock__).count();
    return ld(t)/1e6;
}
void timeit(string msg) {
    cerr << "> " << msg << ": " << precise(6) << getTime() << endl;
}
template<typename T> inline bool maxi(T& a, T b) { return b > a ? (a = b, true) : false; }
template<typename T> inline bool mini(T& a, T b) { return b < a ? (a = b, true) : false; }
const ld PI = asin(1) * 2;
const ld eps = 1e-6;
const int oo = 2e9;
const ll OO = 2e18;
const ll MOD = 1000000007;
const int MAXN = 200000;

struct Dsu {
    vector<int> par;
    vector<int> sz;
    Dsu(int n) {
        FOR(i, 0, n) {
            par.pb(i);
            sz.pb(1);
        }
    }
    int find(int a) {
        return par[a] = a == par[a] ? a : find(par[a]);
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        par[a] = b;
    }
};

int main()
{
    FAST_IO;
    startTime();
    
    int n;
    cin >> n;
    vector<pii> pts(n);
    for(auto& x : pts) cin >> x;

    vector<int> cs(n);
    for(auto& x : cs) cin >> x;

    vector<int> ks(n);
    for(auto& x : ks) cin >> x;

    Dsu dsu(n+1);
    vector<vector<ll>> ws(n+1, vector<ll>(n+1));
    FOR(i, 1, n+1) {
        ws[0][i] = ws[i][0] = cs[i-1];
    }
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            ll dx = abs(pts[i-1].first-pts[j-1].first);
            ll dy = abs(pts[i-1].second-pts[j-1].second);
            ws[i][j] = ws[j][i] = (dx+dy)*(ks[i-1]+ks[j-1]);
        }
    }
    vector<pair<ll, pii>> edges;
    FOR(i, 0, n+1) FOR(j, i+1, n+1) edges.pb({ws[i][j], {i, j}});
    sort(all(edges));
    vector<pii> tree;
    ll wsum = 0;
    // debug(ws);
    for(auto e : edges) {
        ll w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if(dsu.same(u, v)) {
            continue;
        }
        wsum += w;
        dsu.unite(u, v);
        tree.pb({u, v});
    }
    // debug(tree);

    vector<int> pwrs;
    vector<pii> conns;
    for(auto x : tree)  {
        if(x.first == 0) {
            pwrs.pb(x.second);
        } else if(x.second == 0) {
            pwrs.pb(x.first);
        } else {
            conns.pb(x);
        }
    }

    cout << wsum << endl;
    cout << pwrs.size() << endl;
    for(auto x : pwrs) cout << x << " ";
    cout << endl;
    cout << conns.size() << endl;
    for(auto p : conns) cout << p.first << " " << p.second << endl;


    timeit("Finished");
    return 0;
}
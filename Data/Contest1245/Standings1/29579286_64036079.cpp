// clang-format off
#define protected public
using iii  = int;
using yeee = iii;

#ifdef LOCAL
    const iii DEBUG = 0;
#else
    const iii DEBUG = -1;
#endif

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#if 0
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    using namespace __gnu_pbds; template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; template<typename T1, typename T2> using hash_map = gp_hash_table<T1, T2>;
#endif

#define DBG(x) if(DEBUG >= x)
#define FOR(i, lo, hi) for(ll i = ll(lo); i < ll(hi); ++i)
#define ROF(i, hi, lo) for(ll i = ll(hi); i >= (ll)(lo); --i)
#define ALL(x) (x).begin(), (x).end()
#define len(x) ll((x).size())
#define PB push_back

#if 1
    #define DOUT(...) DOUTg(#__VA_ARGS__, __VA_ARGS__)
    template <typename T1> void DOUTf(ostringstream &os, int names_i, vector<string> &names, T1 &&val) { os << names[names_i] << " = " << val; } template <typename T1, typename... Ts> void DOUTf(ostringstream &os, int names_i, vector<string> &names, T1 &&val, Ts &&... vals) { os << names[names_i] << " = " << val << " | "; DOUTf(os, names_i + 1, names, vals...); } template <typename... Ts> string DOUTg(string names, Ts &&... vals) { string special = "()[]{}<>'\"\\"; vector<string> vnames; vnames.PB(""); vector<char> stak; for(char c : names) { bool inside_string = !stak.empty() && (stak.back() == '\'' || stak.back() == '\"'); if(c == '\n') c = ' '; if(c == ' ' && (vnames.back().empty() || (!inside_string && vnames.back().back() == ' '))) continue; if(stak.empty() && c == ',') { if(!vnames.back().empty() && vnames.back().back() == ' ') vnames.back().pop_back(); vnames.PB(""); continue; } vnames.back().PB(c); if(!stak.empty() && stak.back() == '\\') { stak.pop_back(); continue; } size_t p = special.find(c); bool closing = p < 8 && p % 2; if(p == string::npos) continue; if(p == special.size() - 1) { stak.PB(c); continue; } if(stak.empty()) { if(!closing) stak.PB(c); continue; } if(inside_string) { if(c == stak.back()) stak.pop_back(); continue; } if(closing) { if(stak.back() == special[p - 1]) stak.pop_back(); continue; } stak.PB(c); } ostringstream os; DOUTf(os, 0, vnames, vals...); return os.str(); }
    template <template <typename...> class Container, typename T, size_t DIMENSION> struct MultiDimensional { using internal = MultiDimensional<Container, T, DIMENSION - 1>; using type = Container<typename internal::type>; template <typename... Args> static type Generate(T def, const size_t size, Args... sizes) { return type(size, internal::Generate(def, sizes...)); } }; template <template <typename...> class Container, typename T> struct MultiDimensional<Container, T, 1> { using internal = T; using type = Container<T>; static type Generate(T def, const size_t size) { return type(size, def); } }; template <typename T, typename... Args> auto make_vector(T def, Args... sizes) -> typename MultiDimensional<std::vector, T, sizeof...(sizes)>::type { return MultiDimensional<std::vector, T, sizeof...(sizes)>::Generate( def, sizes...); }
#endif
/*get*/ template <typename T> T get() { T x; cin >> x; return x; } /*pair*/ template <typename T1, typename T2> ostream &operator<<(ostream &out, const pair<T1, T2> &cont) { out << "(" << cont.first << ", " << cont.second << ")"; return out; } /*vector*/ template <typename T, typename Alloc> ostream &operator<<(ostream &out, const vector<T, Alloc> &cont) { for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : " ") << *it; return out; } /*deque*/ template <typename T, typename Alloc> ostream &operator<<(ostream &out, const deque<T, Alloc> &cont) { for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : " ") << *it; return out; } /*set*/ template <typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const set<T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << *it; out << "}"; return out; } /*multiset*/ template <typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const multiset<T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << *it; out << "}"; return out; } /*map*/ template <typename Key, typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const map<Key, T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << it->first << ":" << it->second; out << "}"; return out; } /*multimap*/ template <typename Key, typename T, typename Compare, typename Alloc> ostream &operator<<(ostream &out, const multimap<Key, T, Compare, Alloc> &cont) { out << "{"; for(auto it = cont.begin(); it != cont.end(); ++it) out << (it == cont.begin() ? "" : ", ") << it->first << ":" << it->second; out << "}"; return out; } /*vectorND*/ template <typename T> ostream &operator<<(ostream &out, vector<vector<T>> cont) { for(auto it = cont.begin(); it != cont.end(); ++it) out << *it << "\n"; return out; }
using ll = long long; using lll = long long; using ull = unsigned long long; using ld = long double; using pll = pair<ll, ll>; using vb = vector<bool>; using vvb = vector<vb>; using vll = vector<ll>; using vvll = vector<vll>; using vpll = vector<pll>; using point = complex<ld>;
ld get_time() { return ld(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()) / 1e9; } ll sign(ld x) { return (x > 0) - (x < 0); } ll fmod(ll x, ll mod) { if(!mod) return x; if(abs(x) >= mod) x %= mod; if(x < 0) x += mod; return x; } ll pow(ll x, ll exp, ll mod) { ll res = 1, y = x; while(exp) { if(!mod) { if(exp & 1) res = res * y; y = y * y; } else { if(exp & 1) res = fmod(res * y, mod); y = fmod(y * y, mod); } exp >>= 1; } return res; }
ld START_TIME = get_time(); mt19937_64 rand_mt64(chrono::steady_clock::now().time_since_epoch().count()); mt19937 rand_mt(chrono::steady_clock::now().time_since_epoch().count()); const long long INFll = ll(1.1e18) - 1; const int INFi = ll(1.1e9) - 1; ll INF = sizeof(ll) == sizeof(int) ? ll(INFi) : ll(INFll); char newl = '\n';
void main_init(string input_file = "", string output_file = "", bool fast_cio = true) { srand(unsigned(time(0))); if(fast_cio) { ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); } DBG(0 && input_file != "") freopen(input_file.c_str(), "r", stdin); DBG(0 && output_file != "") freopen(output_file.c_str(), "w", stdout); }
// clang-format on

yeee main() {
    main_init();
    //

    ll N = 10;

    vvll B(N, vll(N, 0));
    FOR(y, 0, N)
        FOR(x, 0, N)
            cin >> B[y][x];

    vector<vpll> M(N, vpll(N));
    FOR(y, 0, N) {
        ll d = y % 2 ? 1 : -1;
        FOR(x, 0, N) { M[y][x] = {x + d, y}; }
        ll x = y % 2 ? N - 1 : 0;
        M[y][x] = {x, y - 1};
    }
    DBG(1) cout << M << endl;

    vector<vector<ld>> P(N, vector<ld>(N, 0));
    FOR(y, 0, N) {
        ll x, d;
        if(y % 2) {
            x = N - 1;
            d = -1;
        } else {
            x = 0;
            d = 1;
        }

        FOR(xi, 0, N) {
            pll c = {x, y};
            ll s = 0;
            FOR(di, 0, 6) {
                c = M[c.second][c.first];
                if(c.second < 0) {
                    s = 6 - di;
                    break;
                }
                P[y][x] += (min(P[c.second][c.first],
                                P[c.second - B[c.second][c.first]][c.first]) +
                            1) /
                           6;
            }
            if(x || y)
                P[y][x] = ((P[y][x] + ld(s) / 6) * 6 / (6 - s));
            x += d;
        }
    }

    DBG(1) cout << P << endl;

    cout << setprecision(12) << fixed;
    cout << P[N - 1][0] << endl;
}

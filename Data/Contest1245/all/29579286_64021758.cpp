// clang-format off
#define protected public
using iii  = int;
using yeee = iii;

#ifdef LOCAL
    const iii DEBUG = 10;
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
using ll = int; using lll = long long; using ull = unsigned long long; using ld = long double; using pll = pair<ll, ll>; using vb = vector<bool>; using vvb = vector<vb>; using vll = vector<ll>; using vvll = vector<vll>; using vpll = vector<pll>; using point = complex<ld>;
ld get_time() { return ld(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()) / 1e9; } ll sign(ld x) { return (x > 0) - (x < 0); } ll fmod(ll x, ll mod) { if(!mod) return x; if(abs(x) >= mod) x %= mod; if(x < 0) x += mod; return x; } ll pow(ll x, ll exp, ll mod) { ll res = 1, y = x; while(exp) { if(!mod) { if(exp & 1) res = res * y; y = y * y; } else { if(exp & 1) res = fmod(res * y, mod); y = fmod(y * y, mod); } exp >>= 1; } return res; }
ld START_TIME = get_time(); mt19937_64 rand_mt64(chrono::steady_clock::now().time_since_epoch().count()); mt19937 rand_mt(chrono::steady_clock::now().time_since_epoch().count()); const long long INFll = ll(1.1e18) - 1; const int INFi = ll(1.1e9) - 1; ll INF = sizeof(ll) == sizeof(int) ? ll(INFi) : ll(INFll); char newl = '\n';
void main_init(string input_file = "", string output_file = "", bool fast_cio = true) { srand(unsigned(time(0))); if(fast_cio) { ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); } DBG(0 && input_file != "") freopen(input_file.c_str(), "r", stdin); DBG(0 && output_file != "") freopen(output_file.c_str(), "w", stdout); }
// clang-format on

vll uP, uS;
ll ufind(ll x) { return uP[x] != x ? uP[x] = ufind(uP[x]) : x; }

ll uunion(ll x, ll y) {
    x = ufind(x);
    y = ufind(y);

    if(x == y)
        return -1;

    if(uS[x] > uS[y])
        swap(x, y);

    uS[y] += uS[x];
    uS[x] = 0;
    uP[x] = uP[y];

    return y;
}

using edge = pair<lll, pll>;

yeee main() {
    main_init();
    //

    ll N;
    cin >> N;

    vpll P(N);
    FOR(i, 0, N)
        cin >> P[i].first >> P[i].second;

    vvll C(2, vll(N));
    FOR(i, 0, 2)
        FOR(j, 0, N)
            cin >> C[i][j];

    vector<edge> E;
    FOR(i, 0, N)
        E.PB({C[0][i], {0, i + 1}});

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            E.PB({
                (abs(P[i].first - P[j].first) +
                 abs(P[i].second - P[j].second)) *
                    lll(C[1][i] + C[1][j]),
                {i + 1, j + 1},
            });
        }
    }

    uS.resize(N + 1, 1);
    uP.resize(len(uS));
    FOR(i, 0, len(uP))
        uP[i] = i;

    vector<edge> res;
    sort(ALL(E),
         [](const edge &a, const edge &b) { return a.first < b.first; });
    FOR(i, 0, len(E))
        if(uunion(E[i].second.first, E[i].second.second) != -1)
            res.PB(E[i]);

    lll ress = 0;
    vll res1;
    vpll res2;
    FOR(i, 0, len(res)) {
        ress += res[i].first;
        if(res[i].second.first == 0)
            res1.PB(res[i].second.second);
        else
            res2.PB({res[i].second.first, res[i].second.second});
    }

    cout << ress << newl;
    cout << len(res1) << newl;
    cout << res1 << newl;
    cout << len(res2) << newl;
    for(auto x : res2)
        cout << x.first << " " << x.second << newl;
}

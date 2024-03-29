#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
//#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define mp(a, b) make_pair((a), (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cerr << (#x) << " = " << (x) << endl;

#ifdef MAX_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif

const double PI = 2 * acos(0.0);
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";

template <class T0, class T1>
inline ostream & operator << (ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template <class T0, class T1, class T2>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template <class T0, class T1, class T2, class T3>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " <<  get<3>(a) << "}";
}

template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}



void smain();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef MAX_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\n\n\nTOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}


const int N = 1e5 + 100;

vi g[N];
ll cost[N][3];
int n;

void dfs(int v, vi &a, int par = -1) {
    a.push_back(v);
    for (int to : g[v]) {
        if (to == par)
            continue;
        dfs(to, a, v);
    }
}

void smain() {
    cin >> n;
    fori (z, 3) {
        for (int i = 1; i <= n; ++i) {
            cin >> cost[i][z];
        }
    }
    fori (i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    for (int i = 1; i <= n; ++i) {
        if (g[i].size() >= 3) {
            cout << "-1";
            return;
        }
    }
    vi a;
    int root = 1;
    for (int i = 1; i <= n;++i) {
        if (g[i].size() == 1)
            root = i;
    }
    dfs(root, a);

    vi chose = {0, 1, 2};
    ll best = 1e18;
    vi cur = chose;
//    watch(a);
    do {
        ll cst = 0;
        fori (i, n) {
            cst += cost[a[i]][cur[i % 3]];
        }
        if (cst < best) {
            best = cst;
            chose = cur;
        }
    } while (next_permutation(ALL(cur)));
    vi ans (n + 1);
    fori (i, n) {
        ans[a[i]] = chose[i % 3];
    }
    cout << best << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
}
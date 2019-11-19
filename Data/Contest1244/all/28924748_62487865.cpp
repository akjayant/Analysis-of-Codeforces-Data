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

const int N = 2e5 + 100;
int n, k;
bool a[N];


int parent[N];
int sz[N], lf[N], rf[N];
bool is_set[N];


void make_set(int v) {
    is_set[v] = true;
    parent[v] = v;
    sz[v] = 1;
    lf[v] = rf[v] = v;
}

int find_set(int v) {
    return parent[v] == v ? v : parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    int l = lf[u], r = rf[v];
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    lf[u] = l, rf[u ] = r;
}

void smain() {

    string s;
    cin >> n >> k >> s;
    fori (i, n) {
        a[i] = s[i] == 'W';
    }

    for (int i = 0; i < n; ++i) {
        int l = (i - 1 + n) % n;
        int r = (i + 1) % n;
        if (a[l] != a[i] && a[r] != a[i]) {
            make_set(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        int r = (i + 1) % n;
        if (is_set[i] && is_set[r]) {
            union_sets(i, r);
        }
    }
    if (accumulate(is_set, is_set + n, 0) == n) {
        if (k & 1) {
            fori (i, n) {
                a[i] ^= 1;
            }
        }
    } else {
        fori (i, n) {
            if (is_set[i]) {
                int mn = (i - lf[find_set(i)] + n) % n;
                inmin(mn, (rf[find_set(i)] - i + n) % n);
                ++mn;
                if (mn & 1) {
                    if (k <= mn - 1) {
                        a[i] ^= k & 1;
                    } else {
                        a[i] ^= 1;
                    }
                } else {
                    if (k <= mn - 1) {
                        a[i] ^= k & 1;
                    }
                }
            }
        }
    }
    fori (i, n) {
        cout << (a[i] ? "W" : "B");
    }
}
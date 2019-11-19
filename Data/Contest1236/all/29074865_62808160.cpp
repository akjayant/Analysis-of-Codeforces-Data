#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define int ll
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

ll solve(int n, int m, vi a) {
    vvi qrs(n);
    for (int i = SZ(a) - 1; i >= 0; --i) {
        qrs[a[i]].push_back(i + 1);
    }
    map<int, pii> nearest;
    map<pii, int> dp;
    ll ans = 0;
    m += 2;
    for (int i = n - 1; i >= 0; --i) {
        int j = 0;
        int key = i - j;
        int cur = 0;
        if (nearest.count(key)) {
            pii nrs = nearest[key];
            cur = nrs.first - i + dp[nrs];
        } else {
            cur = min(m, n - i);
        }
//        cerr << "cur[" << i << "] = " << cur << endl;
        ans += cur;

        for (auto id : qrs[i]) {
            int j = id;
            int ii = i - 1;
            int key = ii - j;
            int cur = 0;
            if (nearest.count(key)) {
                pii nrs = nearest[key];
                cur = nrs.first - ii - 1 + dp[nrs];
            } else {
                cur = min(n - ii - 1, m - j - 1);
            }
            key = i - j;
            nearest[key] = {i, j};
            dp[{i, j}] = cur;
        }
    }
    return ans;
}

void smain() {

    int n, m;
    cin >> n >> m;
    vi a(m);
    fori (i, m) {
        cin >> a[i];
        a[i]--;
    }

    if (n == 1) {
        cout << "0";
        return;
    }
    
    int ans = solve(n, m, a);
    reverse(ALL(a));
    int bans = solve(n, m, a);
    cout << ans + bans - n;

}
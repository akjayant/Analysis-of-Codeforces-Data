#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#define TESTS
//#define FILE_IO
#define FILE_IN "input.in"
#define FILE_OUT "bees.out"
#define FAST_IO

#ifndef DEBUG
#define gcd(x, y) __gcd(x, y)
#endif

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
#include <cassert>
#include <climits>
#include <numeric>
#include <functional>
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <bitset>
#include <chrono>
#include <sstream>
#include <fstream>
#include <cstring>
#include <complex>

using namespace std;

#define MP make_pair
#define pb push_back
#define ll long long
#define ld long double
#define cld complex<ld>
#define vcld vector<complex<ld>>
#define ull unsigned ll
#define pll pair<ll, ll>
#define vl vector<ll>
#define vvl vector<vl>
#define vi vector<int>
#define vvi vector<vi>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define kill(x) {ps(x); return;}
#define sz(x) (int)x.size()
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i, a) ROF(i,0,a)
#define rep(n) F0R(_, n)
#define trav(a, x) for (auto& a : x)
#define bits(x) __builtin_popcount(x)
#define bit(x, i) ((((x) >> (i)) & 1) != 0)
#ifdef DEBUG
#define dbg(x...) pr("[",#x,"] = ["), pc(x)
#else
#define dbg(x...) 0x12c
#endif

//mt19937 rng(45123);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF64 = LLONG_MAX;
const int INF32 = 1e9;

//@formatter:off
template<class T> bool chkmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class T, class... Ts> void re(T& t, Ts&... ts) {
        re(t); re(ts...);
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.first,p.second); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    void pr(int x) { cout << x; }
    void pr(long x) { cout << x; }
    void pr(ll x) { cout << x; }
    void pr(unsigned x) { cout << x; }
    void pr(unsigned long x) { cout << x; }
    void pr(unsigned long long x) { cout << x; }
    void pr(float x) { cout << x; }
    void pr(double x) { cout << x; }
    void pr(ld x) { cout << x; }
    void pr(char x) { cout << x; }
    void pr(const char* x) { cout << x; }
    void pr(const string& x) { cout << x; }
    void pr(bool x) { pr(x ? "true" : "false"); }
    template<class T> void pr(const complex<T>& x) { cout << x; }

    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T> void pr(const T& x);

    template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
        pr(t); pr(ts...);
    }
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.first,", ",x.second,"}");
    }
    template<class T> void pr(const T& x) {
        pr("{"); // const iterator needed for vector<bool>
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
        pr("}");
    }

    void ps() { pr("\r\n"); } // print w/ spaces
    template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
    }

    void pc() { pr("]\r\n"); } // debug w/ commas
    template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
        pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
    }
}
using namespace output;
// @formatter:on

void solve();

void precalc();

int main() {
#ifdef FAST_IO
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
#ifdef DEBUG
    auto start = chrono::steady_clock::now();
    freopen("input.in", "r", stdin);
#endif
#ifndef DEBUG
#ifdef FILE_IO
    freopen(FILE_IN, "r", stdin);
    freopen(FILE_OUT, "w", stdout);
#endif
#endif
    precalc();
#ifdef TESTS
    int t;
    cin >> t;
    while (t--)
        solve();
#else
    solve();
#endif
#ifdef DEBUG
    auto end = chrono::steady_clock::now();
    cout << endl << "_______________\nElapsed: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
#endif
    return 0;
}

void precalc() {}

//////////////////////// -- YOUR CODE GOES HERE -- ////////////////////////

vector<set<int>> g;

void solve() {
    int n;
    re(n);
    string a, b;
    re(a, b);
    map<char, int> sc;
    for (char c : a)
        sc[c]++;
    for (char c : b)
        sc[c]++;
    for (auto p: sc)
        if (p.second % 2 != 0) kill("No")
    vector<pair<int, int>> mv;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != b[i]) {
            for (int j = i + 1; j < n; j++)
                if (b[j] == b[i]) {
                    swap(a[i], b[j]);
                    mv.pb({i + 1, j + 1});
                    break;
                }
        }
        if (a[i] != b[i]) {
            for (int j = i + 1; j < n; j++)
                if (a[j] == a[i]) {
                    swap(b[i], a[j]);
                    mv.pb({j + 1, i + 1});
                    break;
                }
        }
        if (a[i] != b[i]) {
            for (int j = i + 1; j < n; j++)
                if (b[j] == a[i]) {
                    swap(a[i + 1], b[j]);
                    swap(a[i + 1], b[i]);
                    mv.pb({i + 2, j + 1});
                    mv.pb({i + 2, i + 1});
                    break;
                }
        }
        dbg(a, b);
    }
    assert(a == b);
    ps("Yes");
    ps(sz(mv));
    for (auto p: mv)
        ps(p.first, p.second);
}

#pragma clang diagnostic pop
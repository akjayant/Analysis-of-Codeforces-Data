#include <algorithm>
#include <array>
#include <assert.h>
#include <chrono>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<ld>> vvld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pll> vpll;

#ifdef OLBOEB
mt19937 rnd(228 + 1488 + 238 + 24111997 % 322);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void print_time() {
#ifdef OLBOEB
    cout.flush();
    cerr << "\ntime: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }


void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<ll, ll> mapa;
    for (ll i = 0; i < n; ++i) {
        ++mapa[a[i]];
    }
    set<pll> setik;
    for (auto& [k, v] : mapa) {
        setik.insert({k, v});
    }
    while (sz(setik) > 1 && k > 0) {
        auto l = setik.begin();
        auto l2 = next(l);
        auto r = --setik.end();
        auto r2 = prev(r);
        if (l->second < r->second) {
            ll shift = k / l->second;
            if (shift == 0) break;
            shift = min(shift, l2->first - l->first);
            k -= shift * l->second;
            if (l->first + shift < l2->first) {
                setik.insert({l->first + shift, l->second});
            } else {
                setik.insert({l2->first, l2->second + l->second});
                setik.erase(l2);
            }
            setik.erase(l);
        } else {
            ll shift = k / r->second;
            if (shift == 0) break;
            shift = min(shift, r->first - r2->first);
            k -= shift * r->second;
            if (r->first - shift > r2->first) {
                setik.insert({r->first - shift, r->second});
            } else {
                setik.insert({r2->first, r2->second + r->second});
                setik.erase(r2);
            }
            setik.erase(r);
        }
    }
    cout << (setik.rbegin()->first - setik.begin()->first) << "\n";
}


int main() {
    cout << fixed << setprecision(20);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

    print_time();
    return 0;
}


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

const ll MAXN = 2e5 + 228;
ll n, k;

struct Block {
    Block(ll l, ll r, ll t) : l(l), r(r), t(t) {}
    Block() : Block(0, 0, 0) {}
    bool is_big() { return r != l + 1 && r != l + 1 - n; }
    ll l, r, t;
};

void solve() {
    cin >> n >> k;
    string s, g;
    cin >> s;
    g = s;
    vl state(n);
    vl cnt(2);
    for (ll i = 0; i < n; ++i) {
        state[i] = s[i] == 'B';
        ++cnt[state[i]];
    }
    for (ll i = 0; i < 2; ++i) {
        if (cnt[i] == 0) {
            cout << s;
            return;
        }
    }

    ll curr = 0;
    auto nxt = [&](ll pos) -> ll { ++pos; if (pos >= n) pos -= n; return pos; };
    auto prv = [&](ll pos) -> ll { --pos; if (pos < 0) pos += n; return pos; };
    while (state[prv(curr)] == state[curr]) { curr = prv(curr); }

    ll start = curr;
    vector<Block> blocks;
    do {
        if (state[curr] != state[prv(curr)]) {
            blocks.emplace_back(curr, nxt(curr), state[curr]);
        } else {
            blocks.back().r = nxt(blocks.back().r);
        }
        curr = nxt(curr);
    } while (curr != start);

    bool has_big = false;
    for (auto b : blocks) {
        has_big |= b.is_big();
    }
    if (!has_big) {
        for (ll i = 0; i < n; ++i) {
            if (k & 1) state[i] = 1 - state[i];
            cout << (state[i] ? 'B' : 'W');
        }
        return;
    }

    ll m = sz(blocks);
    ll sb = 0;
    while (!blocks[sb].is_big()) ++sb;
    ll last_bid_block = sb;
    vl lbb(m);
    for (ll i = 0; i < m; ++i) {
        ll cb = sb + i;
        if (cb >= m) cb -= m;
        if (blocks[cb].is_big()) last_bid_block = cb;
        lbb[cb] = last_bid_block;
    }

    last_bid_block = sb;
    vl nbb(m);
    for (ll i = 0; i < m; ++i) {
        ll cb = sb - i;
        if (cb < 0) cb += m;
        if (blocks[cb].is_big()) last_bid_block = cb;
        nbb[cb] = last_bid_block;
    }

    for (ll i = 0; i < m; ++i) {
        auto& b = blocks[i];
        if (b.is_big()) continue;
        ll l = i - lbb[i];
        if (l < 0) l += m;
        ll r = nbb[i] - i;
        if (r < 0) r += m;
        bool kek = false;
        if (l < r) {
            if (l <= k) {
                state[b.l] = blocks[lbb[i]].t;
                g[b.l] = state[b.l] ? 'B' : 'W';
                kek = true;
            }
        } else if (l >= r) {
            if (r <= k) {
                state[b.l] = blocks[nbb[i]].t;
                g[b.l] = state[b.l] ? 'B' : 'W';
                kek = true;
            }
        }
        if (!kek) {
            if (k & 1) state[b.l] = 1 - state[b.l];
            g[b.l] = state[b.l] ? 'B' : 'W';
        }
    }

    cout << g;
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


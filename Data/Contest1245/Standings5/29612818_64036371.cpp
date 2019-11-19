#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
 
#define int long long
 
vector<int> p;
vector<pii> mn;
 
int getp(int v) {
    return v == p[v] ? v : p[v] = getp(p[v]);
}
 
vector<pii> added;
ll sumcurr = 0;
 
void create(int v, ll x) {
    p[v] = v;
    mn[v] = {x, v};
    sumcurr += x;
}
 
ll edgecost = 0;
 
void unite(int a, int b, ll c) {
    added.pb({a, b});
    a = getp(a);
    b = getp(b);
    if (a == b || sumcurr - max(mn[a].f, mn[b].f) + edgecost + c > sumcurr + edgecost) {
        added.popb();
        return;
    }
    edgecost += c;
    p[a] = b;
    sumcurr -= mn[a].f;
    sumcurr -= mn[b].f;
    checkmin(mn[b], mn[a]);
    sumcurr += mn[b].f;
}
 
ll dist(pii a, pii b) {
    return abs(a.f - b.f) + abs(a.s - b.s);
}
 
void createset(int n, vector<int> c) {
    added.clear();
    p = vector<int>(n);
    mn = vector<pii>(n);
    sumcurr = edgecost = 0;
    for (int i = 0; i < n; ++i) create(i, c[i]);
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pii> pos(n);
    vector<int> c(n), k(n);
    cin >> pos >> c >> k;
    vector<pair<ll, pii>> edge;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            edge.pb({(k[i] + k[j]) * dist(pos[i], pos[j]), {i, j}});
    sort(edge);
    createset(n, c);
    pll answer(sumcurr, -1);
    for (int i = 0; i < sz(edge); ++i) {
        int f = edge[i].s.f;
        int t = edge[i].s.s;
        ll c = edge[i].f;
        unite(f, t, c);
        checkmin(answer, pll(sumcurr + edgecost, i));
    }
    createset(n, c);
    for (int i = 0; i <= answer.s; ++i) {
        int f = edge[i].s.f;
        int t = edge[i].s.s;
        ll c = edge[i].f;
        unite(f, t, c);
    }
    cout << sumcurr + edgecost << '\n';
    cout << n - sz(added) << '\n';
    set<int> used;
    for (int i = 0; i < n; ++i) {
        int p = getp(i);
        if (!used.count(p)) {
            cout << mn[p].s + 1 << ' ';
            used.insert(p);
        }
    }
    cout << '\n';
    cout << sz(added) << '\n';
    for (auto i : added) cout << i.f + 1 << ' ' << i.s + 1 << '\n';
    return 0;
}
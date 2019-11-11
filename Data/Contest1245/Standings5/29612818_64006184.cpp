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
 
void solve() {
    int n;
    vector<int> cnt(3);
    cin >> n >> cnt;
    vector<int> start = cnt;
    vector<vector<int>> ind(3);
    string a = "RPS";
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < sz(a); ++j)
            if (a[j] == s[i]) ind[j].pb(i);
    string ans(n, '0');
    int c = 0;
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        while (cnt[j] && sz(ind[i])) {
            ans[ind[i].back()] = a[j];
            --cnt[j];
            ind[i].popb();
            ++c;
        }
    }
    for (auto &j : ans) {
        for (int i = 0; i < 3; ++i)
            if (j == '0' && cnt[i]) {
                j = a[i];
                --cnt[i];
            }
    }
    for (auto i : cnt)
        assert(i == 0);
    if (c >= (n + 1) / 2) cout << "YES\n" << ans << '\n';
    else cout << "NO\n";
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
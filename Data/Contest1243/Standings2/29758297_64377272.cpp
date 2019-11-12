#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse4")
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <math.h>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long  double ld;
mt19937 rnd(random_device {}());
#define all(a) a.begin(), a.end()
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define pb(x) push_back(x)
#define fr(i, n) for (int i = 0; i < n; ++i)
#define fr1(i, n) for (int i = 1; i <= n; ++i)
const int N = 1<<17;
int a[N];
void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cnt = 0;
    int l = -1, r = -1;
    fr(i, n) {
        cnt += s[i] == t[i];
        if (s[i] != t[i]) {
            if (l == -1) l = i;
            else r = i;
        }
    }
    if (n - cnt != 2) {
        cout << "NO\n";
        return;
    }
    cout << ((s[l] == s[r] && t[r] == t[l]) ? "Yes\n" : "\No\n");
}
void pre_calc() {
   
}
int main() {
    pre_calc();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ABCD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    //cout << -1;
    int tst = 10;
    if (tst != 1) cin >> tst;
    while (tst--)
        solve();
}

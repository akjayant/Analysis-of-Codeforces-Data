#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <math.h>
#include <iomanip>
typedef long long ll;
using namespace std;
#define all(v) v.begin(), v.end()
#define pb push_back
#define ff first
#define ss second
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize "-O3"

vector < vector < int > > g;
vector < vector < ll > > a;
vector < vector < ll > > cost; /// cost[i][j]
/// сколько стоит покрасить если colour [i] = j
vector < int > childs;
vector < int > ord;
void f(int v, int p = -1) {
    ord.pb(v);
    for (auto to: g[v]) {
        if (to == p) continue;
        childs[v]++;
        f(to, v);
    }
}
int main() {
    int n;
    cin >> n;
    childs.resize(n);
    g.resize(n);
    a.resize(n);
    fori(n) a[i].resize(3);
    cost.resize(n);
    fori(n) cost[i].resize(3);
    fori(n) cin >> a[i][0];
    fori(n) cin >> a[i][1];
    fori(n) cin >> a[i][2];
    fori(n - 1) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    int root = -1;
    fori(n) {
        if (g[i].size() == 1) {
            root = i;
            break;
        }
    }
    if (root == -1) {
        cout << -1;
        return 0;
    }
    f(root);
    fori(n) {
        if (childs[i] >= 2) {
            cout << -1;
            return 0;
        }
    }
    vector < int > k;
    k.resize(n);
    ll ans = 1e18;
    for (int c1 = 0; c1 < 3; c1++) {
        for (int c2 = 0; c2 < 3; c2++) {
            if (c1 == c2) continue;
            vector < int > curans;
            ll mn = 0;
            curans.resize(n);
            curans[ord[0]] = c1;
            curans[ord[1]] = c2;
            for (int i = 2; i < n; i++) {
                curans[ord[i]] = 3 - curans[ord[i - 1]] - curans[ord[i - 2]];
            }
            fori(n) mn += a[i][curans[i]];
            if (mn < ans) {
                ans = mn;
                k = curans;
            }
        }
    }
    cout << ans << "\n";
    fori(k.size()) cout << k[i] + 1 << " ";

}


/*


10 100
2 1
3 1
4 1
5 2
6 2
7 3
8 4
9 4
10 4
1 2 3 4 5 6 7 8 9 10
*/

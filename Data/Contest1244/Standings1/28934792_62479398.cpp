#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>
#include <cstdlib>
#include <sstream>
#include <queue>
#include <stack>
#include <cassert>
#include <deque>
#include <list>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pr(x) printf("%d ", x)
#define nl() printf("\n")
#define forn(i, a, b) for(int i=a; i<b; ++i)
#define ford(i, a, b) for(int i=b-1; i>=a; --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
#define X first
#define Y second
#define sqr(x) 1ll*(x)*(x)
#define pb push_back

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vint = vector<int>;
using v2int = vector<vint>;
using vll = vector<ll>;
using ld = long double;
using pld = pair<ld, ld>;

int n;

vector<int> cost[3];

vector<vector<int> > g;

vector<vector<int>> perm = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

vector<int> var;
vector<int> bestVar;

void dfs(int u, int par, const vector<int>& perm, int permIdx, ll& totalCost) {
    var[u] = perm[permIdx];
    totalCost += cost[perm[permIdx]][u];
    for(auto v : g[u]) {
        if (v != par) {
            dfs(v, u, perm, (permIdx + 1)%3, totalCost);
        }
    }
}

void solve() {
    cin>>n;
    g.resize(n);
    forn(c, 0, 3) {
        cost[c].resize(n);
        forn(i, 0, n) {
            cin>>cost[c][i];
        }
    }
    forn(i, 0, n-1) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start;
    forn(i,0, n) {
        if (g[i].size() >2) {
            cout <<-1<<endl;
            return;
        }
        if (g[i].size() == 1)
            start = i;
    }

    var.resize(n);
    ll best_cost = 1e18;
    forn(p, 0, 6) {
        ll total_cost = 0;
        dfs(start, -1, perm[p], 0, total_cost);
        if (total_cost < best_cost) {
            best_cost = total_cost;
            bestVar = var;
        }
    }
    cout <<best_cost<<'\n';
    for (int x : bestVar) {
        cout <<x+1 <<' ';
    }
    cout <<endl;
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    //    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    fprintf(stderr, "Time: %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}

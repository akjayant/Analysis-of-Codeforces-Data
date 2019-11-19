#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <assert.h>
#include <random>
#include <sstream>
#include <clocale>
#include <cstring>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll STRANGE_MOD = 998244353;
const int N = int(3e5) + 111;
const int INF = int(1e9) + 111;
const ll LINF = ll(1e18) + 111;
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define x first
#define y second
using namespace std;

int n;
ll ans = -1;
ll c[3][N];
vector <int> g[N];
vector <int> q;
int used[N];
void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    q.pb(v);
}
int ans2[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("dinner.in");
    //ofstream cout("dinner.out")
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[1][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[2][i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 0; i < n; i++) {
        if (g[i].size() >= 3) {
            cout << -1;
            return 0;
        }
    }
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            x = i;
            break;
        }
    }
    dfs(x);
    for (int c1 = 0; c1 < 3; c1++) {
        for (int c2 = 0; c2 < 3; c2++) {
            if (c1 == c2) continue;
            memset(used, -1, sizeof used);
            used[0] = c1;
            used[1] = c2;
            for (int i = 2; i < n; i++) {
                set <int> a = {0, 1, 2};
                a.erase(used[i - 1]);
                a.erase(used[i - 2]);
                used[i] = (*a.begin());
            }
            ll tmp = 0;
            for (int i = 0; i < n; i++) {
                tmp += c[used[i]][q[i]];
            }
            if (ans == -1) {
                ans = tmp;
                for (int i = 0; i < n; i++) {
                    ans2[i] = used[i];
                }
            } else {
                if (ans > tmp) {
                    ans = min(ans, tmp);
                    for (int i = 0; i < n; i++) {
                        ans2[i] = used[i];
                    }
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        used[q[i]] = ans2[i];
    }
    for (int i = 0; i < n; i++) {
        cout << used[i] + 1 << " ";
    }
    return 0;
}

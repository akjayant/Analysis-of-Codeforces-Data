/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Str(x) to_string(x)
#define len(s) (int)s.size()
#define int long long
typedef long long ll;
typedef long double lld;
typedef string str;
typedef unsigned long long ull;

const int maxn = 1e5 + 228;

vector<int> g[maxn];

const int inf = 1e18;

int pokras[maxn][3];

int dp[maxn][3];

vector<int> kek;

void DFS(int v, int p = -1) {
    kek.pb(v - 1);
    for (auto it : g[v]) {
        if (it != p)
            DFS(it, v);
    }
}

int answer[maxn];

pair<int, int> last[maxn][3];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> pokras[i][0];

    for (int i = 1; i <= n; i++)
        cin >> pokras[i][1];

    for (int i = 1; i <= n; i++)
        cin >> pokras[i][2];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int root = 1, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (len(g[i]) == 1) {
            root = i;
            cnt++;
        }
        if (len(g[i]) > 2) {
            cout << -1;
            return 0;
        }
    }
    if (cnt != 2)
    {
        cout << -1;
        return 0;
    }
    DFS(root);
    vector <int> antihype;
    antihype.pb(0);
    antihype.pb(1);
    antihype.pb(2);
    vector <int> ans;
    int sumans = inf;
    for (int step = 0; step < 6; step++)
    {
        vector <int> answ(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += pokras[kek[i] + 1][antihype[i % 3]];
            answ[kek[i]] = antihype[i % 3];
        }
        if (sum < sumans)
        {
            sumans = sum;
            ans = answ;
        }
        next_permutation(all(antihype));
    }
    cout << sumans << endl;
    for (auto it : ans)
        cout << it + 1 << " ";

    return 0;
}

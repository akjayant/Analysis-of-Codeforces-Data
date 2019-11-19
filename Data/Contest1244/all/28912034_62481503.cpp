#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mpii;
typedef map<int, string> mpis;
typedef map<string, int> mpsi;
typedef map<string, string> mpss;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())
#define pb push_back
#define mp make_pair

#define forr(i, n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i, n)
#define forj(n) forr(j, n)
#define fork(n) forr(k, n)
#define forin fori(n)
#define forjn forj(n)
#define forjm forj(m)
#define forim fori(m)

#define debug(x) cout << #x << " == " << x << endl;
#define GG return 0;

#define int ll

const int MAXN = 100000;


vvi price;
vi graph[MAXN + 2], cols;
vector<bool> used;
int n;

void dfs(int v, int c) {
    used[v] = true;
    cols[v] = c;
    c++;
    c %= 3;
    for (auto u : graph[v]) {
        if (used[u]) continue;
        dfs(u, c);
        c++;
        c %= 3;
    }
}


signed main() // check the limits, dummy
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    price.resize(3, vi(n));
    cols.resize(n, -1);
    fori(3) {
        forjn {
            cin >> price[i][j];
        }
    }

    fori(n - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    forin {
        if (graph[i].size() >= 3) {
            cout << -1;
            return 0;
        }
    }
    used.resize(n, false);
    forin {
        if (graph[i].size() == 1) {
            dfs(i, 0);
            break;
        }
    }
    // dfs(0, 0);

    // 0-0 1-1 2-2
    // 0-0 1-2 2-1
    // 0-1 1-0 2-2
    // 0-1 1-2 2-0
    // 0-2 1-1 2-0
    // 0-2 1-0 2-1

    vector<tuple<int, int, int>> d = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};

    tuple<int, int, int> bst = {0, 1, 2};
    ll sum = 1e16;
    for (const auto& tp : d) {
        vi v(3);
        tie(v[0], v[1], v[2]) = tp;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            cur += price[v[cols[i]]][i];
        }
        if (cur < sum) {
            sum = cur;
            bst = tp;
        }
        // sum = min(cur, sum);
    }

    cout << sum << "\n";
    vi v(3);
    tie(v[0], v[1], v[2]) = bst;
    for (int i = 0; i < n; i++) {
        cout << v[cols[i]] + 1 << " ";
    }
}

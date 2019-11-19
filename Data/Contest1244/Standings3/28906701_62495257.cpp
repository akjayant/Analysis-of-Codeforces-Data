#include <bits/stdc++.h>
#define int long long
#define TTT long long
#define all(x) x.begin(), x.end()
#define forn(n) for (int i = 0; i < n; i++)
#define cint [&](){TTT x; cin >> x; return x;}()
using namespace std;

const int N = 1e5 + 1;
const int inf = 1e17;
void trymax(int& x, int y) {
    x = max(x, y);
}
void trymin(int& x, int y) {
    x = min(x, y);
}
int dp[N][8];
int c[N][3];
vector <int> pr[N][8];
vector <int> a;
vector <int> gr[N];
void dfs(int v, int pr = -1) {
    a.push_back(v);
    for (auto it : gr[v]) {
        if (it != pr) dfs(it, v);
    }
}
    int n;
int check(vector <int> p) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[a[i]][p[i % 3] - 1];
    }
    return ans;
}
signed main () {
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++)  {
            int x;
            cin >> x;
            c[j][i] = x;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (gr[i].size() > 2) return cout << -1, 0;
    }
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (gr[i].size() == 1) v = i;
    }
    dfs(v);
    vector <int> p = {1, 2, 3}, anscol;
    int ans = inf;
    do {
        if (ans > check(p)) {
            anscol = p;
            ans = check(p);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    vector <int> color(n, 0);
    for (int i = 0; i < n; i++) {
        color[a[i]] = anscol[i % 3];
    }
    forn(n) {
        cout << color[i] << ' ';
    }
    return 0;
}

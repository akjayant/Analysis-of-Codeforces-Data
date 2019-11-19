#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define fasty ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define task ""
#define For(a, b, c) for(int a = b; a <= c; ++a)
#define Ford(a, b, c) for(int a = b; a >= c; --a)
#define Fv(a, b) for(auto &a : b)
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x.size())
#define all(a) a.begin(), a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define vt vector<int>
#define vpi vector<pair<int, int>>
#define two(x) (1ll << x)
#define bit(x, i) (x >> i & 1ll)
#define onbit(x, i) (x | (1ll << i))
#define offbit(x, i) (x & ~(1ll << i))
#define int long long

const int N = 2005;
int n, x[N], y[N], id[N], c[N], k[N], cnt;
pair<int, pair<int, int>> xx[N * N + 2000];
int dd[N * N + 2000];

int root(int u) {return id[u] < 0 ? u : id[u] = root(id[u]);}
void  mer(int u, int v) {
    u = root(u), v = root(v);
    if(u == v) return;
    if(id[u] > id[v]) swap(u, v);
    id[u] += id[v];
    id[v] = u;
}

main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    reset(id, -1);
    cin >> n;
    For(i, 1, n) {
        cin >> x[i] >> y[i];
    }
    For(i, 1, n) cin >> c[i];
    For(i, 1, n) cin >> k[i];
    For(i, 1, n) {
        For(j, i + 1, n) {
            int u = ((k[i] + k[j])) * (labs(x[i] - x[j]) + labs(y[i] - y[j]));
            xx[++cnt] = {u, make_pair(i, j)};
        }
    }
    For(i, 1, n) {
        xx[++cnt] = {c[i], {i, n + 1}};
    }
    //cerr << cnt << ' ';
    sort(xx + 1, xx + cnt + 1);
    //reset(id, -1);
    int ans = 0;
    int co = 0, co1 = 0;
    For(i, 1, cnt) {
        int u = xx[i].se.fi, v = xx[i].se.se;
        if(root(u) != root(v)) {
            ans += xx[i].fi;
            mer(u, v);
            if(v == n + 1) dd[i] = 2, co1++;
            else dd[i] = 1, co++;
        }
    }
    cout << ans << '\n' << co1 << '\n';
    For(i, 1, cnt) {
        if(dd[i] == 2) {
            cout << xx[i].se.fi << ' ';
        }
    }
    cout << '\n';
    cout << co << '\n';
    For(i, 1, cnt) {
        if(dd[i] == 1) {
            cout << xx[i].se.fi << ' ' << xx[i].se.se << '\n';
        }
    }
}

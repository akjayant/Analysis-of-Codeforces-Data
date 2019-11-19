/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) { bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48; if (b) x = -x; }
template <typename T> inline void wrip(T x) { if (x > 9) wrip(x / 10); putchar(x%10 + 48); }
template <typename T> inline void write(T x) { if (x < 0) putchar('-'), x = -x; wrip(x);}
void reads(string &s) { char c; while (!isalpha(c = getchar())); s = c; while (isalpha(c = getchar())) s += c; }
typedef const int csint;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef double ld;

const ld pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 11;
const int N = 1e5 + 11;
typedef pair <int, int> ii;
int n, m, pos, res, bac[N], f[N];
set <int> ds, ke[N];
vector <int> cur;
priority_queue<ii, vector <ii>, greater<ii> > Heap;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ke[u].insert(v);
        ke[v].insert(u);
        bac[u]++;
        bac[v]++;
    }
    pos = 1;
    for (int i = 2; i <= n; i++)
        if (bac[pos] > bac[i])
            pos = i;
    for (int i = 1; i <= n; i++)
        if (i != pos)
            ds.insert(i);
    for (int i = 1; i <= n; i++)
        f[i] = inf;
    f[pos] = 0;
    Heap.push(mp(f[pos], pos));
    while (Heap.size()) {
        ii p = Heap.top();
        Heap.pop();
        int u = p.se;
        if (p.fi != f[u])
            continue;
        res += f[u];
        f[u] = 0;
        cur.clear();
        for (auto v : ds)
            if (ke[u].find(v) == ke[u].end() && f[v]) {
                f[v] = 0;
                Heap.push(mp(f[v], v));
                cur.push_back(v);
            }
        for (auto v : cur)
            if (ds.find(v) != ds.end())
                ds.erase(ds.find(v));
        for (auto v : ke[u])
            if (f[v] > 1) {
                f[v] = 1;
                Heap.push(mp(f[v], v));
            }
    }
    cout << res;
}

#include <bits/stdc++.h>

#define need_long 1

#define all(v) v.begin(), v.end()
#define vc vector
#define len(v) ((int) v.size())
#define pr pair
#define ld long double
#define mset multiset

using namespace std;

#if need_long == 1
#define int long long
#else
#endif
const int INF = (need_long) ? 1e18 : 2e9;
mt19937 gen(time(0));

template <class T> int upmax(T &a, T b) {
    return (b > a) ? a = b, 1 : 0;
}

template <class T> int upmin(T &a, T b) {
    return (b < a) ? a = b, 1 : 0;
}

template <class T> void output(vc<T>&a, ostream &out = cerr, string r = " ") {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i] << r;
    }
    out << "\n";
}

const int MAXN = 2500;
const int LOG = 30;

int k[MAXN], x[MAXN], y[MAXN], c[MAXN], d[MAXN][MAXN];

struct sob {
    int cost, u, v;
    sob(int a, int b = -1, int c = -1) : cost(a), u(b), v(c) {}
};

int snm[MAXN], have[MAXN];

int get(int a) {
    if (snm[a] == a)
        return a;
    return snm[a] = get(snm[a]);
}

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    snm[b] = a;
}

bool cmp(sob a, sob b) {
    return a.cost < b.cost;
}

void solve() {
    iota(snm, snm + MAXN, 0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        have[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
        }
    }
    vc <sob> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            q.push_back(sob(d[i][j], i, j));
        }
    }
    sort(all(q), cmp);
    int res = accumulate(c + 1, c + n + 1, 0ll);
    set <int> el;
    for (int i = 1; i <= n; ++i) {
        el.insert(i);
    }
    vc <pr<int, int>> g;
    for (auto i : q) {
        int aa = get(i.u);
        int bb = get(i.v);
        if (aa == bb) continue;
        int d = max(c[have[aa]], c[have[bb]]);
        if (d > i.cost) {
            res -= d;
            res += i.cost;
            g.push_back({i.u, i.v});

            if (d == c[have[aa]]) {
                snm[aa] = bb;
                el.erase(have[aa]);
            }
            else {
                snm[bb] = aa;
                el.erase(have[bb]);
            }
        }
    }
    cout << res << "\n";
    cout << el.size() << "\n";
    for (int i : el) {
        cout << i << " ";
    }
    cout << "\n";
    cout << len(g) << "\n";
    for (auto i : g) {
        cout << i.first << " " << i.second << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 2e3 + 10;
const int mod = 1e9 + 7;
#define int long long
int n;
struct kek
{
    int x;
    int y;
    int z;
};
kek a[N];
vector < kek > v;
int c[N], k[N], mi[N], p[N], rr[N];
int ans =0 ;

bool cmp(kek a, kek b)
{
    return a.z < b.z;
}

int get(int u)
{
    if (p[u] == u) return u;
    return p[u] = get(p[u]);
}

void merge(int u, int v)
{
    if (rr[u] == rr[v]) rr[u]++;
    if (rr[u] < rr[v]) swap(u, v);
    if (c[mi[u]] < c[mi[v]])
    {
        mi[v] = mi[u];
    } else mi[u] = mi[v];
    p[v] = u;
    return;
}

 main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= n; ++i) cin >> c[i], mi[i] = i, ans += c[i], p[i] = i;
    for (int i = 1; i <= n; ++i) cin >> k[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            v.push_back({i, j, (k[i] + k[j]) * (abs(a[i].x - a[j].x) + abs(a[j].y - a[i].y))});
        }
    }
    sort(v.begin(), v.end(), cmp);
    vector < pair < int, int > > eee;
    set < int > ansset;
    for (auto t : v)
    {
        int u = get(t.x);
        int v = get(t.y);
        if (u == v) continue;
        int r = t.z;
        if (max(c[mi[u]], c[mi[v]]) >= r) eee.push_back({t.x, t.y}), ans += r - max(c[mi[u]], c[mi[v]]), merge(u, v);
    }
    for (int i = 1; i <= n; ++i)
    {
        int u = get(i);
        ansset.insert(mi[u]);
    }
    cout << ans <<"\n";
    cout << ansset.size() << "\n";
    for (int i : ansset) cout << i << ' ';
    cout << "\n";
    cout << eee.size() << "\n";
    for (auto ww : eee)
    {
        cout << ww.x << ' ' << ww.y << "\n";
    }
    return 0;
}

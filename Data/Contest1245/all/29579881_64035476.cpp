#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
#define taskname "cf1245"
typedef pair < ll, ll > ii;
typedef pair < ll, ii > iii;
const ll oo = 1e16;

ll n;
ll c[2005];
ll k[2005];
ll P[2005];
ll mask[2005];
vector < ll > f;
vector < ii > g;
pair < ll, ll > a[2005];
pair < ll, ll > _a[2005];
priority_queue < iii, vector < iii >, greater < iii > > q;

int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n;
    ll res = oo;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        _a[i].first = a[i].first - a[i].second;
        _a[i].second = a[i].second - a[i].first;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    int s = min_element(c + 1, c + n + 1) - c;
    ll temp = 0;
    for (int i = 1; i <= n; i++)
        mask[i] = oo;
    while (!q.empty())
        q.pop();
    f.clear();
    g.clear();
    mask[s] = c[s];
    q.push(iii(c[s], ii(s, 1)));
    while (!q.empty())
    {
        ll z = q.top().first;
        ll u = q.top().second.first;
        ll pmask = q.top().second.second;
        q.pop();
        if (mask[u] != z)
            continue;
        temp += mask[u];
        mask[u] = 0;
        if (pmask == 1)
            f.push_back(u);
        else
            g.push_back(ii(u, P[u]));
        for (int v = 1; v <= n; v++)
            if (mask[v] > c[v])
            {
                mask[v] = c[v];
                q.push(iii(mask[v], ii(v, 1)));
            }
        for (int v = 1; v <= n; v++)
        {
            ll cur = (k[u] + k[v]) * (abs(a[u].first - a[v].first) + abs(a[u].second - a[v].second));
            if (mask[v] > cur)
            {
                q.push(iii(cur, ii(v, 2)));
                mask[v] = cur;
                P[v] = u;
            }
        }
    }
    res = min(res, temp);
    cout << res << '\n';
    cout << f.size() << '\n';
    for (int u: f)
        cout << u << " ";
    cout << '\n';
    cout << g.size() << '\n';
    for (auto x : g)
        cout << x.first << " " << x.second << '\n';
}

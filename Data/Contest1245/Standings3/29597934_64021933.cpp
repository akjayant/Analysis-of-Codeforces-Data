#include<bits/stdc++.h>
using namespace std;
typedef pair<long, long> ii;
typedef pair<long long, ii> iii;
struct data
{
    long long x, y;
};
data a[2005];
long long n, c[2005], k[2005];
vector<iii> m;
vector<long> power;
vector<ii> edge;
long par[2005];
long get(long u)
{
    return u == par[u] ? u : par[u] = get(par[u]);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (long i = 1; i <= n; i++) cin >> c[i];
    for (long i = 1; i <= n; i++) cin >> k[i];
    for (long i = 1; i <= n; i++)
    {
        m.push_back({c[i], {n + 1, i}});
    }
    for (long i = 1; i <= n; i++)
    {
        for (long j = i + 1; j <= n; j++)
        {
            long long tmp = (k[i] + k[j]) * (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
            m.push_back({tmp, {i, j}});
        }
    }
    for (long i = 1; i <= n + 1; i++) par[i] = i;
    sort(m.begin(), m.end());
    long long res = 0;
    for (long i = 0; i < m.size(); i++)
    {
        long x = get(m[i].second.first);
        long y = get(m[i].second.second);
        if (x != y)
        {
            par[x] = y;
            res += m[i].first;
            long u = m[i].second.first;
            long v = m[i].second.second;
            if (u == n + 1 || v == n + 1)
            {
                if (u == n + 1) power.push_back(v);
                if (v == n + 1) power.push_back(u);
            }
            else
            {
                edge.push_back({u, v});
            }
        }
    }
    //sort(power.begin(), power.end());
    cout << res << '\n';
    cout << power.size() << '\n';
    for (long i = 0; i < power.size(); i++) cout << power[i] << ' ';
    cout << '\n';
    cout << edge.size() << '\n';
    for (long i = 0; i < edge.size(); i++)
    {
        cout << edge[i].first << ' ' << edge[i].second << '\n';
    }
}

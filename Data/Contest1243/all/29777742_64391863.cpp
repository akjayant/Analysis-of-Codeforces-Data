#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
#define taskname "cf1243"
typedef pair < ll, ll > ii;

int n, m;
ll mask[100005];
ll Pask[100005];
int cnt[100005];
vector < ll > V;
vector < ll > P;
multiset < ll > S;
set < int > a[100005];
priority_queue < ii, vector < ii >, greater < ii > > Q;

int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].insert(y);
        a[y].insert(x);
        cnt[x]++; cnt[y]++;
    }
    ll minn = 1e16, r = 0, res = 0;
    for (ll i = 1; i <= n; i++)
        if (minn > cnt[i])
        {
            r = i;
            minn = cnt[i];
        }
    for (int i = 1; i <= n; i++)
        if (i != r)
            S.insert(i);
    Q.push(ii(0, r));
    for (int i = 1; i <= n; i++)
        mask[i] = 1e16;
    mask[r] = 0;
    while (!Q.empty())
    {
        ll z = Q.top().first;
        ll u = Q.top().second;
        Q.pop();
        if (z != mask[u])
            continue;
        V.clear();
        res += mask[u];
        mask[u] = 0;
        for (auto v: S)
            if (a[u].find(v) == a[u].end() && mask[v] > 0)
            {
                mask[v] = 0;
                Q.push(ii(mask[v], v));
                V.push_back(v);
            }
        P.clear();
        for (auto v: S)
            P.push_back((v == 1));
        for (auto it: V)
            if (S.find(it) != S.end())
                S.erase(S.find(it));
        for (auto v: a[u])
            if (mask[v] > 1)
            {
                mask[v] = 1;
                Pask[v] = mask[v];
                Q.push(ii(mask[v], v));
                Pask[v] = P.back();
                if (P.size() > 0)
                    P.pop_back();
            }
    }
    cout << res;
}

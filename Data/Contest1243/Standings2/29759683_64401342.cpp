#include <bits/stdc++.h>

using namespace std;

long long n, m, res = 0, cnt[1000010], d[1000010];

set <long long> a[1000010];
vector <int> my_vector;
multiset <int> s;
int minn = 1e9 + 5, r = 0;
int x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        a[x].insert(y);
        cnt[x]++;
        a[y].insert(x);
        cnt[y]++;
    }

    for (int i = 1; i <= n; i++)
        if (minn > cnt[i])
        {
            minn = cnt[i];
            r = i;
        }

    s.clear();
    for (int i = 1; i <= n; i++)
        if (i != r) s.insert(i);
    priority_queue <pair<int,int>, vector < pair<int,int> >, greater < pair<int,int> > > q;
    q.push({0, r});
    fill(d + 1, d + n + 1, 1e9 + 5);
    d[r] = 0;
    while (q.size())
    {
        int u = q.top().second, du = q.top().first;
        q.pop();
        if (du != d[u]) continue;
        res += d[u];
        d[u] = 0;
        my_vector.clear();
        for (auto v : s)
            if (a[u].find(v) == a[u].end() && d[v] > 0)
            {
                d[v] = 0;
                q.push({d[v], v});
                my_vector.push_back(v);
            }
        for (auto it : my_vector)
            if (s.find(it) != s.end())
                s.erase(s.find(it));
        for (auto v : a[u]) if (d[v] > 1)
        {
            d[v] = 1;
            q.push({d[v], v});
        }
    }
    //********************
    cout << res;
    return 0;
}

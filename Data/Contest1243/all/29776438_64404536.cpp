#include <bits/stdc++.h>

using namespace std;
#define intMax 1e18
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i >= b; i--)
#define be(a) (a.begin(), a.end())
#define rbe(p) (p.rbegin(), p.rend())
#define pb push_back

map<pair<int, int>, int> mp;
set<int> s;

void dfs(int curr)
{
    vector<int> vals;
    for (int i : s)
    {
        if (mp[{curr, i}] == 0)
        {
            vals.push_back(i);
        }
    }
    for (int i : vals)
    {
        s.erase(i);
    }
    for (int i : vals)
    {
        dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i += 1)
    {
        s.insert(i);
    }
    for (int i = 0; i < m; i += 1)
    {
        int a, b;
        cin >> a >> b;
        mp[{a, b}] = 1;
        mp[{b, a}] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i += 1)
    {
        if (s.size())
        {
            int v = *s.begin();
            s.erase(v);
            dfs(v);
            ans += 1;
        }
        else
        {
            break;
        }
    }
    cout << ans - 1;
}
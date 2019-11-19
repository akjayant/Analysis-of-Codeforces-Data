#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > g;
vector<long long> c1, c2, c3;
vector<long long> c, bc;
vector<long long> p;

vector<bool> used;

void dfs(int v, int d)
{
    used[v] = true;
    c[v] = p[d % 3];
    for(int i = 0; i < g[v].size(); i++)
        if(!used[ g[v][i] ])
            dfs(g[v][i], d + 1);
}

int main()
{
    int n, s = -1;
    cin >> n;
    g.assign(n, vector<int>(0));
    c1.resize(n);
    c2.resize(n);
    c3.resize(n);
    c.resize(n);
    for(int i = 0; i < n; i++)
        cin >> c1[i];
    for(int i = 0; i < n; i++)
        cin >> c2[i];
    for(int i = 0; i < n; i++)
        cin >> c3[i];

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    for(int i = n - 1; i >= 0; i--)
        if(g[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        else if(g[i].size() == 1)
            s = i;

    if(s == -1)
    {
        cout << -1;
        return 0;
    }

    p = {1, 2, 3};
    long long bcnt = 2e18;

    do
    {
        used.clear();
        used.resize(n);
        dfs(s, 0);
        long long cnt = 0;
        for(int i = 0; i < n; i++)
            if(c[i] == 1)
            {
                cnt += c1[i];
            }
            else if(c[i] == 2)
            {
                cnt += c2[i];
            }
            else
            {
                cnt += c3[i];
            }

        if(cnt < bcnt)
        {
            bcnt = cnt;
            bc = c;
        }
    }while(next_permutation(p.begin(), p.end()));

    cout << bcnt << endl;
    for(int i = 0; i < n; i++)
        cout << bc[i] << ' ';

    return 0;
}

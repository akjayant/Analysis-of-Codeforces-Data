#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100003;

int n;
long long cost[4][MAXN];
vector <int> adj[MAXN];
void read()
{
    cin >> n;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
        cin >> cost[i][j];

    for (int i = 1; i <= n-1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int ans1[MAXN];
void solve()
{
    for (int i = 1; i <= n; i++)
        if (adj[i].size() > 2)
    {
        cout << -1 << endl;
        return;
    }

    int ver;

    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1)
        {
            ver = i;
            break;
        }

    vector <int> v;
    int par = -1;
    int curr = ver;

    for (;;)
    {
        v.push_back(curr);
        bool can = false;
        for (auto i: adj[curr])
            if (i != par)
            {
                par = curr;
                curr = i;
                can = true;
                break;
            }

        if (!can)
            break;
    }


    long long ans = 1000000000000000000;
    int i1, j1, k1;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        for (int k = 1; k <= 3; k++)
        if (i != j && i != k && j != k)
    {
        long long curr = 0;
        for (int p = 0; p < n; p++)
        {
            if (p % 3 == 0)
                curr += cost[i][v[p]];

            else
                if (p % 3 == 1)
                curr += cost[j][v[p]];

            else
                curr += cost[k][v[p]];
        }

        if (curr < ans)
        {
            ans = curr;
            i1 = i;
            j1 = j;
            k1 = k;
        }
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            ans1[v[i]] = i1;

        else
            if (i % 3 == 1)
            ans1[v[i]] = j1;

        else
            ans1[v[i]] = k1;
    }

    for (int i = 1; i <= n; i++)
        cout << ans1[i] << " ";

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();
}

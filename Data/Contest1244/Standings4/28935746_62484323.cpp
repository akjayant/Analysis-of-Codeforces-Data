#include <bits/stdc++.h>

#define llong long long

using namespace std;

const llong num = 3;

vector<vector<llong> > a;
vector<vector<llong> > b;
vector<vector<llong> > c;

llong f(llong v, llong p, llong x)
{
    b[x].push_back(v);
    for (llong i = 0; i < a[v].size(); i++)
    {
        if (a[v][i] != p)
        {
            f(a[v][i], v, (x + 1) % num);
        }
    }
}

int main(void)
{
    llong n = 0, x = 0, y = 0, v = 0, ans = 0, k = 0, t = 0;
    vector<llong> m(num, 0);
    for (llong i = 0; i < num; i++)
    {
        m[i] = i;
    }
    cin >> n;
    a.resize(n);
    b.resize(num);
    c.resize(num, vector<llong> (n, 0));
    vector<llong> d(n, 0);
    vector<llong> e(n, 0);
    for (llong i = 0; i < num; i++)
    {
        for (llong j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    for (llong i = 1; i < n; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (llong i = 0; i < n; i++)
    {
        if (a[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if (a[i].size() == 1)
        {
            v = i;
        }
    }
    f(v, -1, 0);
    ans = -1;
    do
    {
        k = 0;
        for (llong i = 0; i < num; i++)
        {
            for (llong j = 0; j < b[i].size(); j++)
            {
                d[b[i][j]] = m[i];
                k += c[m[i]][b[i][j]];
            }
        }
        if (ans == -1 || k < ans)
        {
            ans = k;
            for (llong i = 0; i < n; i++)
            {
                e[i] = d[i];
            }
        }
    } while (next_permutation(m.begin(), m.end()));
    cout << ans << '\n';
    for (llong i = 0; i < n; i++)
    {
        cout << e[i] + 1 << ' ';
    }
    return 0;
}

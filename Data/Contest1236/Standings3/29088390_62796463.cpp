#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

ll poww(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        ll a = poww(x, n / 2);
        return (a * a) % mod;
    }
    return (poww(x, n - 1) * x) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> pos(n * n, -1);
    vector<vector<ll> > ans(n);
    if (n % 2 == 0)
    {
        for (int i = 0; i < n * n / 2; i += n)
        {
            for (int j = i; j < i + n; j++)
            {
                pos[j] = j - i;
                ans[j - i].push_back(j);
                pos[n * n - j - 1] = j - i;
                ans[j - i].push_back(n * n - j - 1);
            }
        }
    }
    else
    {
        for (int i = 0; i < n * (n - 1) / 2; i++)
        {
            pos[i] = i % n;
            ans[i % n].push_back(i);
            pos[n * n - i - 1] = i % n;
            ans[i % n].push_back(n * n - i - 1);
        }
        ll k = 0;
        for (int i = n * (n - 1) / 2; i < n * (n - 1) / 2 + n; i++)
        {
            pos[i] = k;
            ans[k].push_back(i);
            k++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}

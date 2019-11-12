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
    ll N = 100;
    vector<vector<vector<int> > > dp(N + 1, vector<vector<int> > (N + 1, vector<int> (N + 1, 0)));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= N; k++)
            {
                if (i >= 1 && j >= 2)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 2][k] + 3);
                if (j >= 1 && k >= 2)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 2] + 3);
            }
        }
    }

    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << dp[a][b][c] << "\n";
    }

}

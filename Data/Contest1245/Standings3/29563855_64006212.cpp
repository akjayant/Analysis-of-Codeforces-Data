#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

const int maxn = 100005;
const int mod = 1e9 + 7;

ll dp[maxn];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//
    string s;
    cin >> s;
    int n = int(s.size());
    for(int i = 0; i < n; ++i)
        if (s[i] == 'm' || s[i] == 'w')
    {
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    for(int i = 0; i < n; ++i)
    {
        dp[i + 1] = (1ll * dp[i + 1] + dp[i]) % mod;
        if (s[i] == 'n')
        {
            if (i + 1 < n && s[i + 1] == 'n')
            {
                dp[i + 2] = (1ll * dp[i + 2] + dp[i]) % mod;
            }
        }
        else
        if (s[i] == 'u')
        {
            if (i + 1 < n && s[i + 1] == 'u')
            {
                dp[i + 2] = (1ll * dp[i + 2] + dp[i]) % mod;
            }
        }
    }
    cout << dp[n];
    return 0;
}

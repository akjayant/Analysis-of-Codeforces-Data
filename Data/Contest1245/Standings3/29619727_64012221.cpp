#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 5;

int dp[N];

int solve(int k)
{
    if (dp[k] != -1) return dp[k];
    return dp[k] = (solve(k - 1) + solve(k - 2)) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	char pre = s[0];
	int ans = 1;
	memset(dp, -1, sizeof(dp));
	dp[0] = dp[1] = 1;
	for (int i = 0, lim = s.length(), cur = 0; ; ++i)
    {
        if (i == lim)
        {
            ans = (1LL * ans * solve(cur)) % mod;
            break;
        }
        if (s[i] == 'w' || s[i] == 'm')
        {
            ans = 0;
            break;
        }
        if (s[i] != pre)
        {
            pre = s[i];
            ans = (1LL * ans * solve(cur)) % mod;
            cur = 0;
        }
        if (s[i] != 'u' && s[i] != 'n') continue;
        ++cur;
    }
    cout << ans;
    return 0;
}

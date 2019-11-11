#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

#define int long long
const int mod = 1e9 + 7;
string s;
int dp[N];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int n = s.size();
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    int cur = s[0], cnt = 1;
    int ans = 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            cout << 0;
            return 0;
        }
        if (i == 0) continue;
        if (s[i] == cur && (cur == 'u' || cur == 'n')) ++cnt;
        else
        {
            if (cur == 'u' || cur == 'n') ans = ans * dp[cnt] % mod;
            cnt = 1;
            cur = s[i];
        }
    }
    if (cur == 'u' || cur == 'n') ans = ans * dp[cnt] % mod;
    cout << ans;


    return 0;
}

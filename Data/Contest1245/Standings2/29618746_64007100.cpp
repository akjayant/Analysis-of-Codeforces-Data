#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 1000000007
#define maxn 100005

int n;
char s[maxn];
vector<int> v;
ll dp[maxn];

int main()
{
    //freopen("monotonic.in", "r", stdin);
    //freopen("monotonic.out", "w", stdout);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        if (s[i] == 'm' || s[i] == 'w')
        {
            printf("0\n");
            return 0;
        }
    char c = '0';
    int now = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (c != '0' && s[i] == c)
            now++;
        else
        {
            if (now > 1)
                v.push_back(now);
            if (s[i] == 'u' || s[i] == 'n')
            {
                c = s[i];
                now = 1;
            }
            else
            {
                c = '0';
                now = 0;
            }
        }
    }
    //for (int x : v)
    //    printf("%d ", x);
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    ll ans = 1;
    for (int x : v)
        ans = ans * dp[x] % mod;
    cout << ans << endl;

    return 0;
}
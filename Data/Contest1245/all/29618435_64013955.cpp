#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define N 300005
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
string s;
int n;
int kt1 = 0, kt2 = 0;
long long dp[N], res = 1;
int kt = 0;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
//    freopen("A.inp","r",stdin);
//    freopen("A.out","w",stdout);
    cin >> s;
    n = s.size();
    dp[1] = 1;
    dp[2] = 2;
    FOR(i, 3, n)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        if(dp[i] >= MOD) dp[i] -= MOD;
    }
//    cout << dp[3];
    s = ' ' + s;
    FOR(i, 1, n)
    {
        if(s[i] == 'm') kt1 = 1;
        if(s[i] == 'w') kt2 = 1;
    }
    FOR(i, 1, n)
    {
        if((s[i] == 'n' && !kt1) || (s[i] == 'u' && !kt2))
        {
            kt = 1;
            int dem = 1;
            while(i < n && s[i] == s[i + 1])
            {
                i ++;
                dem ++;
            }
            res = (res * dp[dem]) % MOD;
        }
    }
//    cout << dp[3] << "\n";
    if(kt1 || kt2) cout << 0;
    else cout << res;
}

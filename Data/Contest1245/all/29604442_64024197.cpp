#include<iostream>
#include<memory.h>

#define ll long long
using namespace std;

ll dp[100010];
ll mod = (ll)(1e9+7);

string s;

int main()
{
    cin>>s;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < (int)s.size(); ++i)
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
            cout<<0<<endl;
            return 0;
        }
        if(i > 0 && s[i] == 'u' && s[i-1] == 'u')
        {
            dp[i+1] = (dp[i-1] + dp[i+1]) % mod;
        }
        if(i > 0 && s[i] == 'n' && s[i-1] == 'n')
        {
            dp[i+1] = (dp[i-1] + dp[i+1]) % mod;
        }
        dp[i+1] = (dp[i+1] + dp[i]) % mod;
    }
    cout<<dp[(int)s.size()]<<endl;
    return 0;
}

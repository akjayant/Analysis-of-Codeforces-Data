#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int mod=1e9+7;
int len;
int dp[(int)1e5+10];
char s[(int)1e5+10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int i,j;
    dp[0]=1,dp[1]=1;
    for(i=2;i<=1e5+4;i++)
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    cin>>s;
    len=strlen(s);
    ll ans=1;
    for(i=0;i<len;i++)
    {
        if(s[i]=='u')
        {
            int cnt=1;
            while(i+1<len && s[i+1]=='u')
                cnt++,i++;
            ans=(ans*dp[cnt])%mod;
        }
        else if(s[i]=='n')
        {
            int cnt=1;
            while(i+1<len && s[i+1]=='n')
                cnt++,i++;
            ans=(ans*dp[cnt])%mod;
        }
        else if(s[i]=='m' || s[i]=='w')
        {
            ans=0;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

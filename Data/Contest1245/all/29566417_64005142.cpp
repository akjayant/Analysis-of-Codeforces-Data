#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
const int mod=1e9+7;
ll dp[maxn];
int main()
{
    string s;
    cin>>s;
    dp[0]=1;
    int flag=1;
    if(s[0]=='w' || s[0]=='m') flag=0;
    for(int i=1; i<s.size(); i++)
    {
        if(s[i]=='w' || s[i]=='m') flag=0;

        if(s[i]=='n' && s[i-1]=='n')
        {
            if(i==1) dp[i]=2;
            else dp[i]=dp[i-1]+dp[i-2];
        }
        else if(s[i]=='u' && s[i-1]=='u')
        {
            if(i==1) dp[i]=2;
            else dp[i]=dp[i-1]+dp[i-2];
        }
        else dp[i]=dp[i-1];
        dp[i]%=mod;
        //cout<<dp[i]<<endl;
    }
    ll sum=0;
    if(flag) sum=dp[s.size()-1];
    cout<<sum<<endl;
    return 0;
}
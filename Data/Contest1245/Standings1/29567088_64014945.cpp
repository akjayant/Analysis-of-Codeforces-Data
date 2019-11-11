#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;
int dp[N];
char s[N];
int main()
{
    scanf("%s",s+1);
    int ls=strlen(s+1);
    int flag=true;
    for(int i=1;i<=ls;++i)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            flag=false;
            break;
        }
    }
    if(!flag)
    {
        printf("0\n");
        return 0;
    }
    dp[0]=1;
    for(int i=1;i<=ls;++i)
    {
        dp[i]=dp[i-1];
        if(i > 1&&s[i]=='n'&&s[i-1]=='n')
            dp[i]=(dp[i]+dp[i-2])%mod;
        if(i > 1&&s[i]=='u'&&s[i-1]=='u')
            dp[i]=(dp[i]+dp[i-2])%mod;
    }
    cout<<dp[ls]<<endl;
}

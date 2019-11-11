#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long dp[100010];
char s[100010];


int main()
{
    scanf("%s",s);
    if(s[0]=='m' || s[0]=='w')
    {
        printf("0");
        return 0;
    }
    dp[0]=1;
    long long ans=1;
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i]=='m' || s[i]=='w')
        {
            printf("0");
            return 0;
        }
        dp[i]=dp[i-1];
        if(i==1)
        {
            if(s[i]=='n' && s[i-1]=='n')
            {
                dp[i]+=1;
            }
            else if(s[i]=='u' && s[i-1]=='u')
            {
                dp[i]+=1;
            }
            continue;
        }
        if(s[i]=='n' && s[i-1]=='n')
        {
            dp[i]+=dp[i-2];
        }
        else if(s[i]=='u' && s[i-1]=='u')
        {
            dp[i]+=dp[i-2];
        }
        dp[i]%=mod;
        ans=dp[i];
    }
    printf("%I64d",ans);

}

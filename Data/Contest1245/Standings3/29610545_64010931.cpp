#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mod 1000000007ll
#define ll long long
using namespace std;

char s[101000];
ll num[101000];
int n;
ll ans=1;
int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    for(register int i=1;i<=n;i++) if(s[i]=='m' || s[i]=='w') { puts("0");return 0; }
    num[1]=1,num[2]=2;
    for(register int i=3;i<=n;i++) num[i]=(num[i-1]+num[i-2])%mod;
    for(register int i=1;i<=n;i++)
    {
        if(s[i]=='u' || s[i]=='n')
        {
            int len=1;
            while(s[i+len]==s[i]) len++;
            // printf("i=%d %d\n",i,len);
            ans=ans*num[len]%mod;
            i=i+len-1;
        }
    }
    cout<<ans;
    return 0;
}
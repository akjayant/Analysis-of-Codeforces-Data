#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #ifdef _DEBUG
//     const int N=1e3+10;
// #else
    const int N=1e6+10;
// #endif
const int mod=1e9+7;
ll m,n,t,ok,ans=1;
ll d[N];
char s[N];
int main()
{
    // freopen("data.txt","r",stdin);
    d[1]=1,d[2]=2;
    for(int i=3;i<=1e5;i++)
        d[i]=(d[i-1]+d[i-2])%mod;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='m'||s[i]=='w'){ok=1;break;}
        if(s[i]=='n'||s[i]=='u')
        {
            int tmp=1;
            while(s[i+1]==s[i])tmp++,i++;
            ans=(ans*d[tmp])%mod;
        }
    }
    if(ok)puts("0");
    else printf("%lld\n",ans);
}
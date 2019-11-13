//μ's forever
#include <bits/stdc++.h>
#define mod 1000000007
#define N 100005
using namespace std;
inline void write(register int x)
{
    if(!x)putchar('0');if(x<0)x=-x,putchar('-');
    static int sta[20];register int tot=0;
    while(x)sta[tot++]=x%10,x/=10;
    while(tot)putchar(sta[--tot]+48);
}
char s[N];
int len,ans=1,sum;
int bg,ls;
char at;
int f[N][2];
inline int calc(register int a)
{
    return (0ll+f[a][0]+f[a][1])%mod;
}
int main()
{
    scanf("%s",s+1);
    len=strlen(s+1);
    f[0][0]=f[1][0]=1;
    f[0][1]=f[1][1]=0;
    for(register int i=2;i<=len;++i)
    {
        f[i][0]=(0ll+f[i-1][0]+f[i-1][1])%mod;
        f[i][1]=f[i-1][0];
    }
    at=' ';
    for(register int i=1;i<=len;++i)
    {
        if(s[i]=='w'||s[i]=='m')
        {
            puts("0");
            return 0;
        }
        if(s[i]!=at)
        {
            if(at!=' ')
                ans=1ll*ans*calc(ls-bg+1)%mod;
            if(s[i]=='n'||s[i]=='u')
                bg=ls=i,at=s[i];
            else
                at=' ';
        }
        else
            ++ls;
    }
    if(at!=' ')
        ans=1ll*ans*calc(ls-bg+1)%mod;
    write(ans);
	return 0;
}

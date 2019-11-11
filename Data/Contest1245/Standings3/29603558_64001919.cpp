#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dwn(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
int T,n,tim,a,b,c;
char s1[110],s2[110];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    T=read();
    while(T--)
    {
        n=read(),a=read(),b=read(),c=read();
        scanf("%s",s1+1);
        tim=0;
        for(int i=1;i<=n;++i)
        {
            if(s1[i]=='R')
            {
                if(b>0) --b,++tim,s2[i]='P';
                else s2[i]='N';
            }
            else if(s1[i]=='P')
            {
                if(c>0) --c,++tim,s2[i]='S';
                else s2[i]='N';
            }
            else
            {
                if(a>0) --a,++tim,s2[i]='R';
                else s2[i]='N';
            }
        }
        if(tim>=ceil(n/2.0))
        {
            printf("YES\n");
            for(int i=1;i<=n;++i)
            {
                if(s2[i]!='N') putchar(s2[i]);
                else
                {
                    if(a>0) --a,putchar('R');
                    else if(b>0) --b,putchar('P');
                    else --c,putchar('S');
                }
            }
            putchar('\n');
        }
        else printf("NO\n");
    }
    return 0;
}

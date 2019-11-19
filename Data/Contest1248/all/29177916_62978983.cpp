#include <bits/stdc++.h>

using namespace std;

inline int read()
{
    int ret=0,flag=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')flag=-1;c=getchar();}
    while(c>='0'&&c<='9')ret=ret*10+(c^'0'),c=getchar();
    return flag*ret;
}

const int N=1e5+5;
int T,n,m;
int p[N],q[N];

int main()
{
    T=read();
    while(T--)
    {
        n=read();
        for(int i=1;i<=n;i++)p[i]=read();
        m=read();
        for(int i=1;i<=m;i++)q[i]=read();
        int odd=0,even=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i]&1)odd++;
            else even++;
        }
        long long ans=0;
        for(int i=1;i<=m;i++)
        {
            if(q[i]&1)ans+=odd;
            else ans+=even;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

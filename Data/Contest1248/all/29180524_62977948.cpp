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
int T,n,m,sum1,sum2;
ll ans;
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
        ans=sum1=sum2=0;
        n=read();
        rep(i,1,n)
        {
            if(read()%2==0) ++sum2;
            else ++sum1;
        }
        m=read();
        rep(i,1,m)
        {
            if(read()%2==0) ans+=sum2;
            else ans+=sum1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

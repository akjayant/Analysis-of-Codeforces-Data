#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define ha 1000000007
#define ui unsigned int
#define pii pair<int,int>
#define pid pair<int,double>

using namespace std;

inline int read()
{
    char ch=getchar(); int f=1,x=0;
    while (ch<'0' || ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
    while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    return f*x;
}

int n,a[100005];

signed main()
{
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1,[](int x,int y){ return x>y; });
    int hf=(n+1)>>1,sum1=0,sum2=0;
    for (int i=1;i<=hf;i++) sum1+=a[i];
    for (int i=hf+1;i<=n;i++) sum2+=a[i];
    ll ans=1ll*sum1*sum1+1ll*sum2*sum2;
    return !printf("%lld",ans);
}
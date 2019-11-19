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

int t,n,m,a;

signed main()
{
    t=read();
    while (t--)
    {
        n=read();
        int cnt1=0,cnt2=0;
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            a=read();
            if (a&1) cnt1++;
            else cnt2++;
        }
        int c1=0,c2=0;
        m=read();
        for (int i=1;i<=m;i++)
        {
            a=read();
            if (a&1) c1++;
            else c2++;
        }
        ans=1ll*cnt1*c1+1ll*cnt2*c2;
        printf("%lld\n",ans);
    }
    return 0;
}
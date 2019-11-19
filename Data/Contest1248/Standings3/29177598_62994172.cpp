#include <bits/stdc++.h>
using namespace std;
#define mset(var,val) memset(var,val,sizeof(var))
#define rep(i,x,n) for(int i=x;i<n;i++)
#define rep1(i,x,n) for(int i=x;i<=n;i++)
#define per(i,x,n) for(int i=x;i>n;i--)
#define per1(i,x,n) for(int i=x;i>=n;i--)
#define lowbit(x) (x&-x)
#define ls(i) i<<1
#define rs(i) i<<1|1
#define fr first
#define sc second
#define bug printf("------------\n");
#define mkp(a,b) make_pair(a,b)
typedef long long int lli;
typedef unsigned long long ull;
const ull base=131;
//const long long int INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const double PI=acos(-1.0);
const long double eps=1e-7;
const int mod=1e9+7;
const int M=1e6+10;
int n,m;
lli ans,dp[M][2];
lli qpow(lli a,lli b)
{
    lli y=1;
    while(b)
    {
        if(b&1)y=y*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return y;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&m);
    if(m<n)swap(n,m);
    dp[1][0]=1;
    dp[1][1]=1;
    dp[0][0]=dp[0][1]=1;
    rep1(i,2,m)
    {
        dp[i][0]=(dp[i-2][1]+dp[i-1][1])%mod;
        dp[i][1]=(dp[i-2][0]+dp[i-1][0])%mod;
    }
    lli cnt=((dp[m][0]+dp[m][1])%mod-2+mod)%mod;
    if(n==1)
    {
        if(m==1)return 0*printf("2\n");
        else return 0*printf("%lld\n",(cnt+2)%mod);
    }
    //printf("%lld\n",cnt);
    lli ans=(cnt+(dp[n][0]+dp[n][1])%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

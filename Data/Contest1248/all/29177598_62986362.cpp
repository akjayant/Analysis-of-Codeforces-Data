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
int n,a[M];lli sum,sum1;
int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    rep1(i,1,n)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    rep1(i,1,n)
    {
        if(i<=n/2)sum1+=a[i];
        sum+=a[i];
    }
    sum-=sum1;
    lli ans=sum1*sum1+sum*sum;
    printf("%lld\n",ans);
    return 0;
}
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

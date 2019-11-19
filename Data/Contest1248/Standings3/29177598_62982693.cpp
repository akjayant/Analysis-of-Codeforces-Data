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
const int M=1e5+10;
int t,n,m,a[M],b[M];
int main(int argc, char const *argv[])
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        rep1(i,1,n)scanf("%d",&a[i]);
        scanf("%d",&m);
        rep1(i,1,m)scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        int cnt=0;
        rep1(i,1,m)
        {
            //int x,y;
            if((b[i]-a[1])%2==0)
            {
                cnt++;
            }
            else continue;
        }
        lli ans=cnt;
        rep1(i,2,n)
        {
            if((a[i]-a[1])%2==0)ans+=cnt;
            else ans+=m-cnt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

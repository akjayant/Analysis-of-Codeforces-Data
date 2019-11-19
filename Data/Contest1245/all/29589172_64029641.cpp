#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
const ll inf=0x3f3f3f3f3f3f;
const ll INF=~(1LL<<63);
const int N=2050;

struct ansedges
{
    ll x,y;
}e[N];

ll yes[N],x[N],y[N],c[N],k[N];
ll a[N][N],cnt;
ll d[N],fangwen[N],n,PT[N];

inline ll getprim()
{
    mem(d,0x3f);
    d[0]=0;ll ret=0;fangwen[0]=1;
    for(int i=1;i<=n;++i)d[i]=min(d[i],a[0][i]);
    for(int KASE=1;KASE<=n;++KASE){
        ll minn=INF,nowpos=0;
        for(int i=0;i<=n;++i){
			if(fangwen[i]==false&&minn>d[i]){
            	minn=d[i];
            	nowpos=i;
        	}
		}
        fangwen[nowpos]=1;
        ret+=minn;
        if(nowpos&&PT[nowpos])e[++cnt]={nowpos,PT[nowpos]};
        else yes[nowpos]=yes[max(nowpos,PT[nowpos])]=1;
        for(int i=0;i<=n;++i){
            if(nowpos!=i&&d[i]>a[nowpos][i]&&fangwen[i]==false){
                d[i]=a[nowpos][i];
                PT[i]=nowpos;
            }
        }
    }
    return ret;
}

int main()
{
    int T;T=1;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
        for(int i=1;i<=n;++i)cin>>c[i];
        for(int i=1;i<=n;++i)cin>>k[i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            	if(i!=j)a[i][j]=a[j][i]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
        for(int i=1;i<=n;++i)a[0][i]=a[i][0]=c[i];
        ll ans1=getprim();ll ans2=0;
        for(int i=1;i<=n;++i)if(yes[i])++ans2;
        cout<<ans1<<endl;
		cout<<ans2<<endl;
        for(int i=1;i<=n;++i)if(yes[i])printf("%d ",i);
        puts("");cout<<cnt<<endl;
        for(int i=1;i<=cnt;++i)printf("%lld %lld\n",e[i].x,e[i].y);
    }
    return 0;
}

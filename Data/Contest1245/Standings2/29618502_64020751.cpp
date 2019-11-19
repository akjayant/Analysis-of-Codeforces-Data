#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define pb push_back
#define INF 0x3f3f3f3f
#define sc(x) scanf("%d",&x)
#define scc(x,y) scanf("%d%d",&x,&y)
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)
using namespace std;

const int N = 2010;
const int mod = 1 << 30;
const int msk = mod - 1;

std::vector<pair<int,int> > edge;
int f[N],x[N],y[N],c[N],K[N],n;
std::vector<int> point;
LL d[N][N],dist[N];
bool v[N];

int main()
{
    sc(n); int s=1;
    for(int i=1;i<=n;i++) scc(x[i],y[i]);
    for(int i=1;i<=n;i++) 
    {
    	sc(c[i]);
    	if (c[i]<c[s]) s=i;
    }
    for(int i=1;i<=n;i++) sc(K[i]);
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    		d[i][j]=d[j][i]=(LL)(abs(x[i]-x[j])+abs(y[i]-y[j]))*(K[i]+K[j]);
    v[s]=1; LL ans=c[s]; point.pb(s);
    for(int i=1;i<=n;i++) dist[i]=d[s][i];
    for(int i=1;i<n;i++)
    {
    	LL mn=1e18; int k;
    	for(int j=1;j<=n;j++)
    	{
    		if (v[j]) continue;
    		LL tmp=dist[j]>c[j]?c[j]:dist[j];
    		if (tmp<mn) mn=tmp,k=j;
    	}
    	if (mn==c[k]) point.pb(k);
    	else
    	{
    		int ss=0;
    		for(int j=1;j<=n;j++)
    			if (v[j]&&d[j][k]==mn) {ss=j;break;}
    		edge.pb({ss,k});
    	}
    	v[k]=1; ans+=mn;
    	for(int j=1;j<=n;j++)
    		if (!v[j]) dist[j]=min(dist[j],d[k][j]);
    }
    printf("%lld\n",ans);
    printf("%d\n",point.size());
    for(int i=0;i<point.size();i++)
    	printf("%d%c",point[i]," \n"[i==point.size()-1]);
    printf("%d\n",edge.size());
    for(int i=0;i<edge.size();i++)
    	printf("%d %d\n",edge[i].fi,edge[i].se);
    return 0;
}

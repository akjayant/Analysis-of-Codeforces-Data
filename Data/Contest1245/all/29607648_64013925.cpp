#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000+5;
ll dis[maxn],g[maxn][maxn];
bool book[maxn],mark[maxn];
ll ans;
ll c[maxn],k[maxn],x[maxn],y[maxn];
int n,pre[maxn];
vector<int> city;
vector<pair<int,int> > edge;
int main()
{
	dis[0]=0x3f3f3f3f3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	int k1=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
		dis[i]=c[i];mark[i]=true;
	}
	for(int i=1;i<=n;i++)scanf("%lld",&k[i]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		g[i][j]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
	}
	int cnt=0;
	while(cnt<n)
	{
		k1=0;
		for(int i=1;i<=n;i++)if(dis[k1]>dis[i]&&!book[i])k1=i;
		book[k1]=true;ans+=dis[k1];
		if(mark[k1])city.push_back(k1);
		else edge.push_back(make_pair(k1,pre[k1]));
		for(int i=1;i<=n;i++)if(!book[i]&&dis[i]>g[k1][i])
		{dis[i]=g[k1][i];mark[i]=false;pre[i]=k1;}
		cnt++;
	}
	cout<<ans<<endl<<city.size()<<endl;
	for(int i=0;i<city.size();i++)cout<<city[i]<<" ";
	cout<<endl;
	cout<<edge.size()<<endl;
	for(int i=0;i<edge.size();i++)cout<<edge[i].first<<" "<<edge[i].second<<endl; 
} 
/* 
 * Author: Imagine_I
 * Time: 2019-10-13 18:07:19
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll a1[maxn],a2[maxn],a3[maxn];
vector<int> G[maxn];
int c[maxn];
ll dfs(int now,int fa,int col)
{
	ll a=0;
	c[now]=col;
	if(col==1) a+=a1[now];
	if(col==2) a+=a2[now];
	if(col==3) a+=a3[now];
	for(int i=0;i<G[now].size();i++)
	{
		if(G[now][i]==fa) continue;
		ll Min=a;
		for(int j=1;j<=3;j++)
		{
			if(j==c[now]||j==c[fa]) continue;
			if(a==Min) a+=dfs(G[now][i],now,j);
			else
			{
				int cc=c[G[now][i]];
				ll w=dfs(G[now][i],now,j);
				if(w+Min<a)
				{
					a=w+Min;
				}
				else dfs(G[now][i],now,cc);
			}
		}
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a1[i];
	for(int i=1;i<=n;i++) cin>>a2[i];
	for(int i=1;i<=n;i++) cin>>a3[i];
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(G[i].size()>2)
		{
			cout<<-1<<'\n';
			return 0;
		}
		if(G[i].size()==1&&pos==0) pos=i;
	}
	//cout<<pos<<'\n';
	ll out;
	out=dfs(pos,0,1);
	memset(c,0,sizeof(c));
	out=min(out,dfs(pos,0,2));
	memset(c,0,sizeof(c));
	out=min(out,dfs(pos,0,3));
	memset(c,0,sizeof(c));
	//cout<<out<<'\n';
	for(int i=1;i<=3;i++)
	{
		if(out==dfs(pos,0,i))
		{
			cout<<out<<'\n';
			for(int i=1;i<=n;i++) cout<<c[i]<<(i==n?'\n':' ');
			break;
		}
		else memset(c,0,sizeof(c));
	}
	return 0;
}

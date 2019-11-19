#include<bits/stdc++.h>
using namespace std;
vector<int>v;
set<int>s[1000001];
int vis[1000001];
void dfs(int u)
{
	vector<int>rem;
	vis[u]=1;
	for(int j=0;j<v.size();j++)
	{
		if(s[u].count(v[j])==0)
		{
			int p=v[j];
			v.erase(v.begin()+j);
			rem.push_back(p);
			j--;
		}
	}
	for(int i=0;i<rem.size();i++)
		dfs(rem[i]);
}
signed main() 
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		v.push_back(i);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		s[u].insert(v);
		s[v].insert(u);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			v.erase(lower_bound(v.begin(),v.end(),i));
			dfs(i);
			ans++;
		}
	printf("%d",ans-1);
	return 0;
}
/*
3 3
1 2
2 3
3 1

6 11
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6
2 3
1 3
*/
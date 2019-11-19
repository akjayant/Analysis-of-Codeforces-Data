#include<bits/stdc++.h>
using namespace std;
set <int> adj[100005],unvisited;
int ans,n,m,i;
void bfs(int x)
{
	queue<int>q;
	q.push(x);
	unvisited.erase(unvisited.find(x));
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		ans++;
		vector<int>temp;
		for(set <int>::iterator it=unvisited.begin();it!=unvisited.end();++it)
			if(adj[u].find(*it)==adj[u].end()){temp.push_back(*it);q.push(*it);}
		for(i=0;i<temp.size();++i)unvisited.erase(unvisited.find(temp[i]));
	}
}
int main()
{
	ios::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);
	cin>>n>>m;
	int x,y;
	for(i=0;i<m;++i){cin>>x>>y;x--;y--;adj[x].insert(y);adj[y].insert(x);}
	if(m==0){cout<<0;return 0;}
	for(i=0;i<n;++i)unvisited.insert(i);
	vector<int>v;
	for(i=0;i<n;++i)
	{
		if(unvisited.find(i)!=unvisited.end())
		{
			ans=0;
			bfs(i);
			v.push_back(ans);
		}
	}
	cout<<v.size()-1;
 
	return 0;
}
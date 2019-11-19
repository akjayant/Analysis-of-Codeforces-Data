#include <bits/stdc++.h>
using namespace std;

void DFS(long long index, long long prev, long long next, long long arr[], vector<vector<long long> > &adj, vector<vector<long long> > &v, long long l, int vis[], vector<vector<pair<long long, long long> > >&w)
{
	
	long long curr;
	if(prev+next==1)
	curr = 2;
	else if(prev+next==2)
	curr=1;
	else
	curr = 0;
	w[index].push_back({l,curr+1});
	arr[index]+= v[curr][l];
	vis[l] = 1;
	for(int i = 0; i < adj[l].size(); i++)
	{
		if(vis[adj[l][i]]==0)
		DFS(index, curr, prev, arr, adj, v, adj[l][i], vis, w);
	}
}
int main() {
    long long n;
    cin >> n;
    vector<vector<long long> >v(3);
    for(long long i = 0; i < 3; i++)
    {
    	v[i].resize(n+1);
    	for(long long j = 0; j < n; j++)
    	cin >> v[i][j+1];
	}
	vector<vector<long long> >adj(n+1);
    for(long long i = 0; i< n-1; i++)
    {
    	long long a, b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
	}
	long long l=-1;
	for(long long i = 1; i<=n; i++)
	{
		if(adj[i].size() > 2 || adj[i].size()==0)
		{
			cout << -1;
			return 0;
		}
		if(adj[i].size()==1)
		l = i;
	}
	if(l==-1)
	{
		cout << -1<<endl;
		return 0;
	}
	long long arr[6] = {0};
	vector<vector<pair<long long, long long> > > w(6);
	long long k = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i!=j)
			{
				int vis[n+1] = {0};
				DFS(k, i, j, arr, adj, v, l, vis, w);
				k++;
			}
		}
	}
	long long p = arr[0];
	for(long long i = 0; i < k; i++)
	p = min(p, arr[i]);
	cout << p<<endl;
	for(int i = 0; i < k; i++)
	{
		if(p==arr[i])
		{
			sort(w[i].begin(), w[i].end());
			for(int j = 0; j < w[i].size(); j++)
			cout << w[i][j].second <<" ";
			return 0;
		}
	}
}

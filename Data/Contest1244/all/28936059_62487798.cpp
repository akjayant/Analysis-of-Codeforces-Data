#include<bits/stdc++.h>

using namespace std;


vector<int> g[100000];
int c[3][100000];
int color[100000];


int addc(int c1, int c2)
{
	if(c2 < c1)
		swap(c1, c2);
	
	if(c1 == 0 && c2 == 1)
		return 2;
	if(c1 == 0 && c2 == 2)
		return 1;
	if(c1 == 1 && c2 == 2)
		return 0;

}
void dfs(int v, int c1, int c2, int p, long long &sum)
{
	int cur = addc(c1, c2);
	//cerr << "has " << c1 << "  " << c2 << " -> " << cur << endl;
	//cerr << "want to color v = " << v << "in color " << cur << " and add to sum " << c[cur][v] << endl; 
	color[v] = cur;
	sum += c[cur][v];
	for(auto to : g[v])
	{
		if(to == p)
			continue;
		dfs(to, c2, cur, v, sum);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int t = 0; t < 3; t ++)
		for(int i = 0 ; i < n; i ++)
			cin >> c[t][i];
	
	for(int i = 0; i < n-1; i ++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int st = 0;	
	for(int i = 0 ; i < n; i ++)
	{
		if(g[i].size() == 1)
			st = i; 
		if(g[i].size() > 2)
		{
			cout << -1;
			return 0;
		}
	}
	//cerr << "start = " << st << endl;
	long long ans = 1e18;
	pair<int, int> pc;
	//cerr << "size = " << g[st].size() << endl;

	for(int c1 = 0; c1 < 3; c1 ++)
		for(int c2 = 0; c2 < 3; c2 ++)
		{
			if(c1 == c2)
				continue;
			long long cur = 0;
			dfs(st, c1, c2, -1, cur);		
			if(ans > cur)
			{
				ans = cur;
				pc = {c1, c2};
			}
		}
	cout << ans << endl;
	
	long long cur = 0;
	//cerr << pc.first << " " <<  pc.second << endl;
	dfs(st, pc.first, pc.second, -1, cur);		
	
	for(int i = 0 ; i < n; i ++)
		cout << color[i]+1 << " ";		
		
	return 0;
}
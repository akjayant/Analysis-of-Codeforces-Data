#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 10000000002
#define N 2001

int g[N][N];

int distanc(pair<int,int>& p1,pair<int,int>& p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}



int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int,int>> v(n + 1);
    vector<int> par(n + 1);

    set<pair<int,int>> s;
    vector<int> fdist(n + 1,inf);
    for(int i = 1;i <= n;i++)
    {
    	cin >> v[i].first >> v[i].second;
    	par[i] = 0;
    }
    vector<int> c(n + 1);
    for(int i = 1;i <= n;i++)
    {
    	cin >> c[i];
    	g[0][i] = c[i];
    	fdist[i] = c[i];
    	s.insert({c[i],i});
    }
    vector<int> k(n + 1);
    for(int i = 1;i <= n;i++)
    {
    	cin >> k[i];
    }
    for(int i = 1;i <= n;i++)
    {
    	for(int j = i + 1;j <= n;j++)
    	{
    		int dist = (k[i] + k[j]) * distanc(v[i],v[j]);
    		// cerr << i << " " << j << " " << dist << endl;
    		g[i][j] = g[j][i] = dist;
    	}
    }
    set<int> chose;
    int ans = 0;
    vector<int> marked(n +  1, 0);
    while(!s.empty())
    {
    	pair<int,int> p = *s.begin();
    	s.erase(s.begin());
    	if(marked[p.second])
    		continue;
    	marked[p.second] = 1;
    	ans += p.first;
    	// cerr << p.first << " " << p.second << endl;
    	for(int i = 1;i <= n;i++)
    	{
    		int ndist = g[p.second][i];
    		if(ndist < fdist[i] and marked[i] == 0)
    		{
    			fdist[i] = ndist;
    			par[i] = p.second;
    			s.insert({ndist,i});
    		}
    	}
    }
    vector<int> built;
    vector<pair<int,int>> edges;
    for(int i = 1;i <= n;i++)
    {
    	if(par[i] == 0)
    	{
    		built.push_back(i);
    	}
    	else	
    		edges.push_back({par[i],i});
    }
    cout << ans << endl;
  
    
    cout << built.size() << endl;
    for(auto it : built)
    	cout << it << " ";
    cout << endl;
    cout << edges.size() << endl;
    for(auto it : edges)
    	cout << it.first << " " << it.second << endl;;





	return 0;
}
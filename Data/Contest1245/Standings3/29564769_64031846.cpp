#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
 
const int mod = 1e9+7;
 
vector< set<int> > v;
int n;
vector<int> id, sz, c, k;
int cost[2002][2002];
 
void init()
{
	for(int i = 0;i<n;i++)
		id[i] = i, sz[i] = 1;
}
int find(int x)
{
	if(id[x] == x)
		return x;
	return id[x] = find(id[x]);
}
int merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y)
		return 0;
	if(sz[x] < sz[y])
		swap(x, y);
	id[y] = x;
	sz[x] += sz[y];
	return 1;
}
int dfs(int u, int p)
{
	int ret = u;
	for(int i: v[u])
		if(i!=p)
		{
			int x = dfs(i, u);
			if(c[x] < c[ret])
				ret = x;
		}
 
	return ret;
}
 
#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin>>n;
	vector< pair<int, int> > coor(n);
	for(int i = 0;i<n;i++)
		cin>>coor[i].first>>coor[i].second;
	id.resize(n);
	v.resize(n);
	sz.resize(n);
	init();
	c.resize(n);
	k.resize(n);
	for(int i = 0;i<n;i++)
		cin>>c[i];
	for(int i = 0;i<n;i++)
		cin>>k[i];
 
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			cost[i][j] = (abs(coor[i].first - coor[j].first) + abs(coor[i].second - coor[j].second)) * (k[i] + k[j]);
	vector< pair<int, pair<int, int> > > edges, e2;
	for(int i = 0;i<n;i++)
		for(int j = i+1;j<n;j++)
			edges.push_back({cost[i][j], {i, j}});
	sort(edges.begin(), edges.end());
	int sz = edges.size();
	int anstn = 0;
	for(int i = 0;i<sz;i++)
	{
		if(merge(edges[i].second.first, edges[i].second.second))
		{
			v[edges[i].second.first].insert(edges[i].second.second);
			v[edges[i].second.second].insert(edges[i].second.first);
			anstn += edges[i].first;
			e2.push_back(edges[i]);
		}
	}
	reverse(e2.begin(), e2.end());
	set<int> vv;
	vv.insert(dfs(0, -1));
	anstn += c[*vv.begin()];
	int ans = anstn;
	vector< set<int> > vans = v;
	for(int i = 0;i<n-1;i++)
	{
		int x = e2[i].second.first, y = e2[i].second.second, cc = e2[i].first;
		int temp = dfs(x, -1);
		anstn -= c[temp];
		anstn -= cc;
		v[x].erase(y);
		v[y].erase(x);
		int temp2 = dfs(x, -1), temp3 = dfs(y, -1);
		anstn += c[temp3];
		anstn += c[temp2];
		if(anstn < ans)
		{
			vv.erase(temp);
			vv.insert(temp2);
			vv.insert(temp3);
			ans = anstn;
			vans = v;
		}
		else
		{
			anstn -= c[temp2] + c[temp3];
			anstn += cc + c[temp];
			v[x].insert(y);
			v[y].insert(x);
		}
	}
	vector< pair<int, int> > anse;
	for(int i = 0;i<n;i++)
		for(int j = i+1;j<n;j++)
			if(vans[i].find(j) != vans[i].end())
				anse.push_back({i, j});
	cout<<ans<<endl;
	cout<<vv.size()<<endl;
	for(int i: vv)
		cout<<i+1<<" ";
	cout<<endl<<anse.size()<<endl;
	for(auto p: anse)
		cout<<p.first+1<<" "<<p.second+1<<endl;
 
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

#define INF 100000000000007

#define MAX_N 100007

long long par[MAX_N];
long long ranka[MAX_N];

void init(long long n)
{
	for(long long i=0;i<n;i++)
	{
		par[i]=i;
		ranka[i]=0;
	}
}

int find(long long x) {
	if(par[x]==x)
	{
		return x;
	}
	else
	{
		return par[x] = find(par[x]);
	}
}

void unite(long long x,long long y)
{
	x=find(x);
	y=find(y);
	if(x==y)return;

	if(ranka[x]<ranka[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(ranka[x]==ranka[y])ranka[x]++;
	}
}

bool same(long long x,long long y)
{
	return find(x)==find(y);
}



long long n;
vector<vector<long long>> dist;

int main()
{
	cin >> n;
	vector<long long> x(n);
	vector<long long> y(n);
	for(long long i=0;i<n;i++)
		cin >> x[i] >> y[i];
	vector<long long> c(n);
	vector<long long> k(n);
	for(long long i=0;i<n;i++)
		cin >> c[i];
	for(long long i=0;i<n;i++)
		cin >> k[i];
	
	dist=vector<vector<long long>>(n+1,vector<long long>(n+1,INF));

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dist[i][j]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
	for(int i=0;i<n;i++)
	{
		dist[i][n]=c[i];
		dist[n][i]=c[i];
	}

	init(n+1);
	set<int> e;
	for(int i=0;i<n+1;i++)
		e.insert(i);
	vector<pair<long long,pair<long long,long long>>> branch;
	for(int i=0;i<n+1;i++)
		for(int j=i+1;j<n+1;j++)
		{
			branch.push_back(make_pair(dist[i][j],make_pair(i,j)));
			//cout << i << " : " << j << " : " << dist[i][j] << endl;
		}
	sort(branch.begin(),branch.end());
	vector<pair<int,int>> ans;
	vector<pair<int,int>> ans2;
	long long cost=0;
	for(auto itr=branch.begin();itr!=branch.end();itr++)
	{
		auto nx=*itr;
		long long d=nx.first;
		long long xx=nx.second.first;
		long long yy=nx.second.second;

		//cout << xx << " " << yy << " " << d << endl;
		if(same(xx,yy))continue;
		else
		{
			unite(xx,yy);
			cost+=d;
			if(yy==n or xx==n)
				ans2.push_back(make_pair(xx,yy));
			else	
				ans.push_back(make_pair(xx,yy));
		}
	}
	cout << cost << endl;
	cout << ans2.size() << endl;
	for(int i=0;i<ans2.size();i++)
		cout << ans2[i].first+1 << (i==ans2.size()-1 ? "\n":" ");
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i].first+1 << " " << ans[i].second+1 << endl;

}
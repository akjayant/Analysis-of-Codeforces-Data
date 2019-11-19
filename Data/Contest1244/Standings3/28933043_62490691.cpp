#include <bits/stdc++.h>

using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define int long long
const int N=1e6,INF=1e18;
int col[3][N];
int dp[N][3];
int color[N];
vector<int> gr[N];
vector<int> mas;
void dfs(int v,int pr=-1)
{
	mas.push_back(v);
	for(auto j:gr[v])if(j!=pr)dfs(j,v);
}
 main()
{
	int n;
	cin>>n;
	fr(i,0,n)
	{
		cin>>col[0][i];
	}
	fr(i,0,n)
	{
		cin>>col[1][i];
	}
	fr(i,0,n)
	{
		cin>>col[2][i];
	}
	int x,y;
	fr(i,0,n-1)
	{
		cin>>x>>y;
		x--;y--;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	int st=-1;
	bool can=1;
	fr(i,0,n)
	{
		if(gr[i].size()>2)can=0;
		if(gr[i].size()==1)st=i;
	}
	dfs(st);
	int choosed=0;
	int ans=INF;		
	int q=0;
	for(int i=0;i<n;i++)
	{
		if(i%3==0)q+=col[0][mas[i]];
		if(i%3==1)q+=col[1][mas[i]];
		if(i%3==2)q+=col[2][mas[i]];
	}
	ans=min(q,ans);
	if(ans==q)
	{
		for(int i=0;i<n;i++)
		{
			if(i%3==0)color[mas[i]]=0;
			if(i%3==1)color[mas[i]]=1;
			if(i%3==2)color[mas[i]]=2;
		}
	}


	q=0;
	for(int i=0;i<n;i++)
	{
		if(i%3==0)q+=col[0][mas[i]];
		if(i%3==1)q+=col[2][mas[i]];
		if(i%3==2)q+=col[1][mas[i]];
	}
	ans=min(q,ans);
	if(ans==q)choosed=1;
	if(ans==q)
	{
		for(int i=0;i<n;i++)
		{
			if(i%3==0)color[mas[i]]=0;
			if(i%3==1)color[mas[i]]=2;
			if(i%3==2)color[mas[i]]=1;
		}
	}

	q=0;
	for(int i=0;i<n;i++)
	{
		if(i%3==0)q+=col[1][mas[i]];
		if(i%3==1)q+=col[0][mas[i]];
		if(i%3==2)q+=col[2][mas[i]];
	}
	ans=min(q,ans);
	if(ans==q)
	{
		for(int i=0;i<n;i++)
		{
			if(i%3==0)color[mas[i]]=1;
			if(i%3==1)color[mas[i]]=0;
			if(i%3==2)color[mas[i]]=2;
		}
	}


	q=0;
	for(int i=0;i<n;i++)
	{
		if(i%3==0)q+=col[1][mas[i]];
		if(i%3==1)q+=col[2][mas[i]];
		if(i%3==2)q+=col[0][mas[i]];
	}
	ans=min(q,ans);
	if(ans==q)
	{
		for(int i=0;i<n;i++)
		{
			if(i%3==0)color[mas[i]]=1;
			if(i%3==1)color[mas[i]]=2;
			if(i%3==2)color[mas[i]]=0;
		}
	}


	q=0;
	for(int i=0;i<n;i++)
	{
		if(i%3==0)q+=col[2][mas[i]];
		if(i%3==1)q+=col[1][mas[i]];
		if(i%3==2)q+=col[0][mas[i]];
	}
	ans=min(q,ans);
	if(ans==q)
	{
		for(int i=0;i<n;i++)
		{
			if(i%3==0)color[mas[i]]=2;
			if(i%3==1)color[mas[i]]=1;
			if(i%3==2)color[mas[i]]=0;
		}
	}


	q=0;
	for(int i=0;i<n;i++)
	{
		if(i%3==0)q+=col[2][mas[i]];
		if(i%3==1)q+=col[0][mas[i]];
		if(i%3==2)q+=col[1][mas[i]];
	}
	ans=min(q,ans);
	if(ans==q)
	{
		for(int i=0;i<n;i++)
		{
			if(i%3==0)color[mas[i]]=2;
			if(i%3==1)color[mas[i]]=0;
			if(i%3==2)color[mas[i]]=1;
		}
	}

	if(can==0)cout<<-1;
	else{
	cout<<ans<<'\n';
	fr(i,0,n)
	{
		cout<<color[i]+1<<' ';
	}
}
}
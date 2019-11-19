#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<queue>
using namespace std;
typedef pair<long long ,int> P;
int n;
vector<int> ans1;
vector<P> ans2;
long long cost[2020][2020];
long long mincost[2020];
bool used[2020];
int nxt[2020];
bool vis[2020][2020];
priority_queue<P,vector<P>,greater<P> > que;
struct point
{
	long long x,y,k,c;
}p[2020];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].c;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].k;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long lp=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
			lp*=p[i].k+p[j].k;
			cost[i][j]=lp;
			cost[j][i]=lp;
		}
	}
	long long res;
	for(int sta=1;sta<=1;sta++)
	{
		res=0;
		for(int i=1;i<=n;i++)
		{
			used[i]=false;
			mincost[i]=p[i].c;
			que.push(P(mincost[i],i));
		}
		while(!que.empty())
		{
			P p0=que.top();
			que.pop();
			int v=p0.second;
			if(used[v])
			{
				continue;
			}
			used[v]=true;
			res+=mincost[v];
			if(mincost[v]==p[v].c)
			{
				ans1.push_back(v);
			}
			for(int i=1;i<=n;i++)
			{
				if(used[i])
				{
					continue;
				}
				if(mincost[i]>cost[i][v])
				{
				    mincost[i]=cost[i][v];
				    que.push(P(mincost[i],i));
				    nxt[i]=v;
				}
			}
		}
	}
	cout<<res<<endl;
	int x=ans1.size();
	printf("%d\n",x);
	for(int i=0;i<x;i++)
	{
		printf("%d ",ans1[i]);
	}
	x=0;
	for(int i=1;i<=n;i++)
	{
		if(nxt[i])
		{
			x++;
		}
	}
	//printf("A%d\n",cost[2][3]);
	printf("\n");
	printf("%d\n",x);
	for(int i=1;i<=n;i++)
	{
		if(nxt[i])
		{
			printf("%d %d\n",i,nxt[i]);
		} 
	}
	return 0;
} 
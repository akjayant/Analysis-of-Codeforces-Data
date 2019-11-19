#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
map<int,int>f[M];
int fa[M];
int find_fa(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find_fa(fa[x]);
}
int main()
{
	int n,m;
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		f[x][y]=1;
		f[y][x]=1; 
	}
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!f[i].count(j))
				{
					int x=find_fa(i);
					int y=find_fa(j);
					if(x!=y)
					{
						num++;
						fa[x]=y;
					}
				}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int num_i=0;
			for(int j=i+1;j<=n;j++)
			{
				if(!f[i].count(j))
				{
					num_i++;
					int x=find_fa(i);
					int y=find_fa(j);
					if(x!=y)
					{
						num++;
						fa[x]=y;
					}
				}
				if(num_i==500)
					break;
			}
		}
	}
	cout<<n-1-num<<endl;
	return 0;
}
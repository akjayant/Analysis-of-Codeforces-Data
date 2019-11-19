#include <bits/stdc++.h>
using namespace std;
const int M = 2000100;
int in[M];
int a[M],b[M],c[M];
int now[M],lennow,d[M];
struct node
{
	int to,next;
}edge[M];
int num,p[M],n,anspl[M];
void add(int x,int y)
{
	num++;
	edge[num].to=y;
	edge[num].next=p[x];
	p[x]=num;
}
void dfs(int x,int y)
{
	now[++lennow]=x;
	for(int i=p[x];i!=0;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v!=y)
			dfs(v,x);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		in[x]++;
		in[y]++;
	} 
	int root=0,flag=0;
	long long ans=(1ll<<60);
	for(int i=1;i<=n;i++)
	{
		if(in[i]>=3)
			flag=1;
		if(in[i]==1)
			root=i;
	}
	if(flag)
	{
		printf("-1");
		exit(0);
	}
	dfs(root,0);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
			if(i!=j)
			{
				d[1]=i;
				d[2]=j;
				for(int k=3;k<=n;k++)
					d[k]=6-d[k-1]-d[k-2];
				long long sum=0;
				for(int k=1;k<=n;k++)
				{
					if(d[k]==1)
						sum+=a[now[k]];
					if(d[k]==2)
						sum+=b[now[k]];
					if(d[k]==3)
						sum+=c[now[k]]; 
				}
				if(sum<ans)
				{
					ans=sum;
					for(int k=1;k<=n;k++)
						anspl[now[k]]=d[k];
				}
			}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<anspl[i]<<" ";
	return 0;
}
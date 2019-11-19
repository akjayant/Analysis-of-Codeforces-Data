#include<bits/stdc++.h>
#define LL long long
using namespace std;

int c[100005][4];
struct E{
	int to,nxt;
}b[200005];
int fst[100005],tot;
void insert(int f,int t)
{
	b[++tot]=(E){t,fst[f]};fst[f]=tot;
	b[++tot]=(E){f,fst[t]};fst[t]=tot;
}
bool use[100005];
int dfn[100005],dfs_c;
void dfs(int x)
{
	use[x]=1;
	dfn[++dfs_c]=x;
	for(int i=fst[x];i;i=b[i].nxt)
	{
		int v=b[i].to;
		if(!use[v]) dfs(v);
	}
}

int rd[100005];
int col[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&c[i][1]);
    for(int i=1;i<=n;i++)
    	scanf("%d",&c[i][2]);
    for(int i=1;i<=n;i++)
    	scanf("%d",&c[i][3]);
    for(int i=1;i<n;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	rd[x]++,rd[y]++;
    	insert(x,y);
	}
	int cnt=0,x;
	for(int i=1;i<=n;i++)
		if(rd[i]==1) x=i,cnt++;
	if(cnt!=2) puts("-1");
	else
	{
		LL ans=1e16+1;
		int pos=0;
		dfs(x);
		for(int k=1;k<=3;k++)
		{
			LL tot=0;
			for(int i=1;i<=n;i++)
			{
				tot+=c[dfn[i]][(i+k)%3+1];
			}
			if(tot<ans)
			{
				ans=tot;
				for(int i=1;i<=n;i++)
					col[dfn[i]]=(i+k)%3+1;
			}
		}
		for(int k=1;k<=3;k++)
		{
			LL tot=0;
			for(int i=1;i<=n;i++)
				tot+=c[dfn[i]][((k-i)%3+3)%3+1];
			if(tot<ans)
			{
				ans=tot;
				for(int i=1;i<=n;i++)
					col[dfn[i]]=((k-i)%3+3)%3+1;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			printf("%d ",col[i]);
	}
}

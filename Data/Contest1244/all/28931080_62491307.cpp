#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector <int> v[100050];
int du[100050];
ll c[5][100050];
int color[100050];
int fir,sec;
ll tmp;
ll ans=9999999999999999LL;
void dfs(int u,int c1,int c2,int fa)
{
	int c3=6-c1-c2;
//	printf("%d %d %d\n",c1,c2,c3);
    if(u==sec)tmp+=c[c2][u];
    else tmp+=c[c3][u];
    for(int i=0;i<v[u].size();++i)
    {
        if(v[u][i]==fa)continue;
        if(u==sec)dfs(v[u][i],c1,c2,u);
        else dfs(v[u][i],c2,c3,u);
    }
}
void dfs2(int u,int c1,int c2,int fa)
{
	int c3=6-c1-c2;
//	printf("%d %d %d\n",c1,c2,c3);
    if(u==sec)tmp+=c[c2][u],color[u]=c2;
    else tmp+=c[c3][u],color[u]=c3;
    for(int i=0;i<v[u].size();++i)
    {
        if(v[u][i]==fa)continue;
        if(u==sec)dfs2(v[u][i],c1,c2,u);
        else dfs2(v[u][i],c2,c3,u);
    }
}

void work(int c1,int c2)
{
    tmp=c[c1][fir];
    dfs(sec,c1,c2,fir);
    ans=min(ans,tmp);
}
void work2(int c1,int c2)
{
	tmp=c[c1][fir];
	color[fir]=c1;
    dfs2(sec,c1,c2,fir);
    if(tmp==ans)
    {
    	printf("%lld\n",ans);
    	for(int i=1;i<=n;++i)printf("%d ",color[i]);
    	exit(0);
	}
}

int main()
{
    cin>>n;
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&c[i][j]);
        }
    }
    for(int i=1;i<n;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        du[x]++;
        du[y]++;
        if(du[x]>2||du[y]>2)return puts("-1"),0;
    }
    for(int i=1;i<=n;++i)
    {
        if(du[i]==1)
        {
            fir=i;
            sec=v[i][0];
            break;
        }
    }
    work(1,2);work(2,1);
    work(1,3);work(3,1);
    work(2,3);work(3,2);
    work2(1,2);work2(2,1);
    work2(1,3);work2(3,1);
    work2(2,3);work2(3,2);
    printf("%lld\n",ans);
    return 0;
}

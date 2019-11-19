#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
const int COLOR[6][3]=
{
    {0,1,2},
    {0,2,1},
    {1,0,2},
    {1,2,0},
    {2,0,1},
    {2,1,0}
};

int n;
struct Edge{int v,to;}E[M<<1];int Head[M],e_tot,Deg[M];
void Link(int u,int v){E[++e_tot]=(Edge){v,Head[u]},Head[u]=e_tot,Deg[u]++;}

int A[3][M],Col[6][M];
long long Ans[6];

void dfs(int u,int f,int c,int col)
{
    Ans[c]+=A[COLOR[c][col]][u];
    Col[c][u]=COLOR[c][col];
    for(int i=Head[u];i;i=E[i].to)
    {
        int v=E[i].v;if(v==f)continue;
        dfs(v,u,c,(col+1)%3);
    }
}

void Solve()
{
    for(int i=1;i<=n;i++)if(Deg[i]>2){puts("-1");return;}
    int rt;for(int i=1;i<=n;i++)if(Deg[i]==1){rt=i;break;}
    dfs(rt,-1,0,0);
    dfs(rt,-1,1,0);
    dfs(rt,-1,2,0);
    dfs(rt,-1,3,0);
    dfs(rt,-1,4,0);
    dfs(rt,-1,5,0);
    int pos=-1;long long Min=2e18;
    for(int i=0;i<6;i++)if(Ans[i]<Min)Min=Ans[i],pos=i;
    printf("%lld\n",Min);
    for(int i=1;i<=n;i++)printf("%d ",Col[pos][i]+1);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&A[0][i]);
    for(int i=1;i<=n;i++)scanf("%d",&A[1][i]);
    for(int i=1;i<=n;i++)scanf("%d",&A[2][i]);
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        Link(u,v);Link(v,u);
    }
    Solve();
    return 0;
}
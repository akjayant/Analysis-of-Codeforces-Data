#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int n,m,nxt[200001],lst[200001],ans[200001],cnt;
bool vis[200001],pd[200001];
queue<int>Q;
vector<int>G[200001];

int vis1[10100],prim[10000+10],cnt1=0;//?????? nlogn    调和级数的复杂度

void getprim()
{
    int nn=10000+10;
    memset(vis1,0,sizeof(vis1));
    for(int i=2;i<=nn;i++)
    {
        if(vis1[i]==0)
        {
            prim[++cnt1]=i;
            for(int j=i+i;j<=nn;j=j+i)
                vis1[j]=1;

        }

    }
}
void delet(int x)
{
    nxt[lst[x]]=nxt[x];
    lst[nxt[x]]=lst[x];
}
int main()
{
    int i,u,v,j;
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    getprim();
    int aa=4343;
    for (i=1;i<n;i++) nxt[i]=i+1,lst[i+1]=i;
    nxt[0]=1;
    aa++;
    for (i=1;i<=n;i++)
        if (vis[i]==0)
        {
            ans[++cnt]=1;vis[i]=1;
            aa++;
            Q.push(i);delet(i);
            while (Q.empty()==0)
            {
                int u=Q.front();
                Q.pop();
                for (j=0;j<G[u].size();j++)
                    if (vis[G[u][j]]==0) pd[G[u][j]]=1;
                for (j=nxt[0];j;j=nxt[j])
                {
                    if (pd[j]==0)
                    {
                        aa++;
                        vis[j]=1;
                        ans[cnt]++;
                        Q.push(j);
                        int dffdd=454;
                        delet(j);
                        dffdd++;
                    }
                    else pd[j]=0;
                }
            }
        }
    sort(ans+1,ans+cnt+1);
    aa++;
    int bbb=4345;
    cout<<cnt-1<<endl;
//    for (i=1;i<cnt;i++)
//        printf("%d ",ans[i]),bbb++;
    bbb++;
//    cout<<ans[cnt]<<endl;
}
#include<bits/stdc++.h>

const int maxn=102020;

struct node
{
    int t,next;
}e[maxn<<2];
int head[maxn],cnt;
void add(int u,int v)
{
    e[cnt]=node{v,head[u]};
    head[u]=cnt++;
}
bool vis[maxn],vi[maxn];
int d[maxn];
int ans[maxn];

int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
    int n,m,u,v;
    scanf("%d%d",&n,&m);
        memset(head,-1,sizeof head);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        for(int i=1;i<=n;i++)d[i]=i;
        int dtop=n,top=0;
 
        memset(vis,0,sizeof vis);
        memset(vis,0,sizeof vi);
        std::queue<int>q;
        for(int j=1;j<=n;j++)if(!vis[j])
        {
            ans[top++]=0;
            q.push(j);
            while(!q.empty())
            {
                int u=q.front();q.pop();
                vis[u]=1;
                ans[top-1]++;
                for(int i=head[u];~i;i=e[i].next)
                    if(!vis[e[i].t])
                        vi[e[i].t]=1;
                for(int i=1;i<=dtop;)
                {
                    if(!vis[d[i]]&&!vi[d[i]])
                    {
                        q.push(d[i]);
                        d[i]=d[dtop--];
                    }
                    else vi[d[i++]]=0;
                }
            }
        }
        std::sort(ans,ans+top);
        printf("%d\n",top-1);
}
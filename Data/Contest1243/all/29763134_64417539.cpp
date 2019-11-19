#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
const int N = 210000;

struct Edge
{
    int v,next;
}edge[N];
int head[N],e;
int num[N];
void erase()
{
    e = 0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}
bool bn[N];
bool tbn[N];
struct ss
{
    int u,v,w;
}sn[4840000];
bool cmp(ss a,ss b)
{
    return a.w<b.w;
}
int fa[N];
int findfa(int a)
{
    if(fa[a] == a) return a;
    return fa[a] = findfa(fa[a]);
}

int main()
{
    int t,i,j,k;
    int n,m;
    cin>>n>>m;
    int u,v;
    erase();
    memset(num,0,sizeof(num));
    for(i = 0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
        num[u]++;
        num[v]++;
    }
    if(n<=2200)
    {
        int num = 0;
        for(i = 1;i<=n;i++)
        {
            memset(tbn,0,n+1);
            for(t = head[i];t!=-1;t = edge[t].next)
            {
                int v = edge[t].v;
                tbn[v] = 1;
            }
            for(j = 1;j<=n;j++)
            {
                if(tbn[j] == 0)
                {
                    sn[num].u = i,sn[num].v = j,sn[num].w = 0;
                }
                else
                {
                    sn[num].u = i,sn[num].v = j,sn[num].w = 1;
                }
                num++;
            }
        }

        sort(sn,sn+num,cmp);
        for(i = 1;i<=n;i++)
            fa[i] = i;
        int ans = 0;
        for(i = 0;i<num;i++)
        {
            int u = sn[i].u,v = sn[i].v;
            int w = sn[i].w;
            //cout<<u<<" "<<v<<" "<<w<<endl;
            int fu = findfa(u),fv = findfa(v);
            if(fv == fu) continue;
            ans += w;
            fa[fu] = fv;
        }
        cout<<ans<<endl;
    }
    else
    {
        int sn = sqrt(n);
        int tmp;
        int ans = 0;
        for(i = 1;i<=n;i++)
        {
            if(num[i]<=sn)
            {
                tmp = i;
                break;
            }
        }
        memset(bn,0,n+1);
        for(t = head[tmp];t!=-1;t = edge[t].next)
        {
            int v = edge[t].v;
            bn[v] = 1;
        }
        for(i = 1;i<=n;i++)
        {
            if(bn[i])
            {
                memset(tbn,0,n+1);
                for(t = head[i];t!=-1;t = edge[t].next)
                {
                    int v = edge[t].v;
                    tbn[v] = 1;
                }
                bool bb = 0;
                for(j = 1;j<=n;j++)
                {
                    if(tbn[j] == 0&&bn[j] == 0)
                    {
                        bb = 1;
                        break;
                    }
                }
                if(!bb) ans++;
                bn[i] = 0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

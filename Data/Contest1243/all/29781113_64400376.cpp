#include <bits/stdc++.h>
using namespace std;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';return n?-x:x;}
#define in hmt()
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define getbit(i,x) ((x>>i)&1ll)
#define ii pair<int,int>

const int maxn=1e5+5;
int id[maxn],fre[maxn],C[maxn];
int n,m,D,cnt;
string s[maxn];
vector<int> g[maxn],nhom[maxn];
vector<pair<int,int>> e;

int TIM(int x)
{
    return id[x]==x?x:id[x]=TIM(id[x]);
}
void DFS(int s)
{
    queue<int> q;
    q.push(s);
    id[s]=TIM(s+1);
    nhom[cnt].push_back(s);C[s]=cnt;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto &v:g[x]) fre[v]=x;
        for(int i=TIM(1);i<=n;i=TIM(i+1))
        {
            if(fre[i]!=x)
            {
                id[i]=TIM(i+1);
                q.push(i);
                nhom[cnt].push_back(i);
                C[i]=cnt;
            }
        }
    }
    ++cnt;
}
void update(int i,char C,int id)
{
    for(auto &v:nhom[i]) s[id][v-1]=C;
}
void GET(int x,int id)
{
    D=max(id,D);
    if(x==1||x==2) return;
    GET(x/2,id+1);
    GET(x-x/2,id+1);
}
main()
{
    //freopen("test.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    forinc(i,0,m-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        e.push_back({u,v});
        //cout<<u<<" "<<v;
        //return 0;
    }
    forinc(i,1,n+1) id[i]=i;
    for(int i=1;i<=n;i=TIM(i+1)) DFS(i);
    //return 0;
    GET(cnt,0);D++;
    forinc(i,0,n-1) s[0].push_back('0');
    forinc(i,1,D-1) s[i]=s[0];
    //GG(0,cnt,0);
    cout<<cnt-1<<"\n";
}

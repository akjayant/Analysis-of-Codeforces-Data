//#include<bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//const int maxn=2e3+10;
////int a[maxn];
//ll mod=1e9+7;
//ll qpow(ll a,ll n)
//{
//    ll ans=1;
//    while(n)
//    {
//        if(n&1)
//            ans=ans*a%mod;
//        a=a*a%mod;
//        n>>=1;
//    }
//    return ans;
//}
//struct node
//{
//    int x,y;
//    int id;
//    int c,k;
//    int flag;
//    int jianzao;
//};
//node p[maxn];
//int c[maxn];
//int k[maxn];
//ll dp[maxn][maxn];
//vector<int> v;
//struct EDGE
//{
//    int from,to;
//    ll  dis;
//    EDGE(int from,int to,ll dis):from(from),to(to),dis(dis){}
//    bool friend operator <(EDGE a,EDGE b)
//    {
//        return a.dis>b.dis;
//    }
//};
//priority_queue<EDGE>q[maxn];
//vector<int>aa;
//vector<pair<int,int> >bb;
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    p[n].c=2e9;
//    int pos=n;
//
//    for(int i=0;i<n;i++)
//        scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i,p[i].flag=0,p[i].jianzao=1;
//    for(int i=0;i<n;i++)
//    {
//        scanf("%d",&p[i].c);
//        if(p[pos].c>p[i].c)
//        {
//            pos=i;
//        }
//    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=i;j<n;j++)
//        {
//            if(i!=j)
//                dp[i][j]=(ll)(p[i].k+p[j].k)*(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y));
//            else dp[i][j]=p[i].c;
//            q[i].push(EDGE(i,j,dp[i][j]));
//            q[j].push(EDGE(j,i,dp[i][j]));
//        }
//    }
//    ll ans=0;
//    for(int i=0;i<n;i++)
//        scanf("%d",&p[i].k);
//    v.push_back(pos);
//    p[pos].flag=1;
//    p[pos].jianzao=1;
//    ans+=p[pos].c;
//    aa.push_back(pos);
//    int cnt=1;
//    while(cnt<n)
//    {
//        pos=n;
//        for(int i=0;i<n;i++)
//        {
//            if(p[i].flag==0&&p[i].c<p[pos].c)
//            {
//                pos=i;
//            }
//        }
//        ll cost1=p[pos].c;
//        ll cost2;
//        ll tp=2e18;
//        int pos2=0;
//        for(int i=0;i<v.size();i++)
//        {
//            while(!q[i].empty())
//            {
//                EDGE now=q[i].top();
//                if(p[now.to].flag==1)
//                {
//                    q[i].pop();
//                    continue;
//                }
//                if(now.dis<tp)
//                {
//                      tp=now.dis;
//                      pos2=now.to;
//                }
//                break;
//            }
//        }
//        cost2=tp;
//        if(cost1<cost2)
//        {
//            p[pos].jianzao=1;
//            p[pos].flag=1;
//            v.push_back(pos);
//            ans+=cost1;
//
//        }
//        else
//        {
//            p[pos2].jianzao=0;
//            p[pos2].flag=1;
//            v.push_back(pos2);
//            ans+=cost2;
//        }
//        cnt++;
//    }
//
//
//    return 0;
//}
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int maxn=100000+10;
const int maxm=2222;
const ll mod=1e9+7;
ll mp[maxm][maxm];
ll val[maxm],k[maxm];
struct pp
{
    ll x,y;
}a[maxm<<2];

struct node
{
    ll from,to,dis;
    node(ll from,ll to,ll dis):from(from),to(to),dis(dis)
    {
    }
};

struct node2
{
    int x,y;
    int id;
    int c,k;
    int flag;
    int jianzao;
};
vector<node> g;
int pre[maxn];

bool cp(const node&a,const node&b)
{
    return a.dis<b.dis;
}
int ffind(int x)
{
    return pre[x]==x?x:pre[x]=ffind(pre[x]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        pre[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&val[i]);
    }
    for(int i=1;i<=n;i++)
    {
        g.push_back(node{0,i,val[i]});
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            mp[i][j]=mp[j][i]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            mp[i][j]=mp[j][i]=mp[i][j]*(k[i]+k[j]);
            g.push_back(node{i,j,mp[i][j]});
        }
    }
    sort(g.begin(),g.end(),cp);
    int u,v,w;
    int prex,prey,c=0;
    ll ans=0;
    vector<pii> vv;
    vector<int> v1;
    for(int i=0;i<g.size();i++)
    {
        u=g[i].from;
        v=g[i].to;
        w=g[i].dis;
        prex=ffind(u);
        prey=ffind(v);
        if(ffind(u)!=ffind(v))
        {
            ans+=w;
            pre[prex]=prey;
            if(u!=0&&v!=0)
                vv.push_back({u,v});
            else
                v1.push_back(max(u,v));
            if(++c==n)
                break;
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",v1.size());
    for(int i=0;i<v1.size();i++)
        printf("%d ",v1[i]);

    puts("");
    printf("%d\n",vv.size());
    for(int i=0;i<vv.size();i++)
        printf("%d %d\n",vv[i].first,vv[i].second);
    return 0;
}

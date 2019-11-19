#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
#define ll long long
#define mod 1000000007
#define maxx 100005
using namespace std;
int pre[2005];
int n;
void init()
{
    for(int i=0;i<=n;i++)pre[i]=i;
}
int findd(int x)
{
    return pre[x]==x?x:pre[x]=findd(pre[x]);
}
struct node
{
    int x,y;
    ll val;
    node(int x,int y,ll val):x(x),y(y),val(val){}
    friend bool operator <(node x1,node x2)
    {
        return x1.val<x2.val;
    }
};
vector<node> edge;
struct node2
{
    int x,y;
    int k;
}p[2005];
vector<int>pp;
vector<pair<int,int>> e;
int main()
{
    cin>>n;
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    int c;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c);
        edge.push_back(node(0,i,c));
    }
    for(int i=1;i<=n;i++)scanf("%d",&p[i].k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
        {
            ll cost=(ll)(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y))*(p[i].k+p[j].k);
            edge.push_back(node(i,j,cost));
        }
    sort(edge.begin(),edge.end());
    ll ans=0;
    for(int i=0;i<edge.size();i++)
    {
        int x=edge[i].x;
        int y=edge[i].y;
        int xx=findd(x);
        int yy=findd(y);
        if(xx!=yy)
        {
            pre[xx]=yy;
            ans+=edge[i].val;
            if(x==0)pp.push_back(y);
            else e.push_back(make_pair(x,y));
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",pp.size());
    for(int i=0;i<pp.size()-1;i++)printf("%d ",pp[i]);
    printf("%d\n",pp[pp.size()-1]);
    printf("%d\n",e.size());
    for(int i=0;i<e.size();i++)printf("%d %d\n",e[i].first,e[i].second);
    return 0;
}
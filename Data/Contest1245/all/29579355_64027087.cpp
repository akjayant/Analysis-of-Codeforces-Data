#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e6+10;
struct node{
    int x,y;
    ll dis;
    bool operator<(const node b)const
    {
        return dis<b.dis;
    }
}e[N];
ll ans;
int m,n,t,cnt,cnt1;
int x[2010],y[2010],c[2010],k[2010],p[2010];
vector<pair<int,int>>tmp;
vector<int> tmp1;

int fi(int x)
{
    return p[x]==x?x:p[x]=fi(p[x]);
}
int main()
{
    // freopen("data.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)p[i]=i;
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            e[++t].x=i,e[t].y=j;
            e[t].dis=(ll)(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
        }
    for(int i=1;i<=n;i++)
    {
        e[++t].x=n+1,e[t].y=i;
        e[t].dis=c[i];
    }
    sort(e+1,e+t+1);
    for(int i=1;i<=t;i++)
    {
        int x1=e[i].x,y1=e[i].y;
        x1=fi(x1),y1=fi(y1);
        if(x1!=y1)
        {
            ans+=e[i].dis;
            if(e[i].x==n+1||e[i].y==n+1)tmp1.push_back((e[i].x==n+1?e[i].y:e[i].x));
            else tmp.push_back(make_pair(e[i].x,e[i].y));
            p[x1]=y1;if(++cnt==n)break;
        }
    }
    printf("%lld\n%d\n",ans,(int)tmp1.size());
    for(int i=0;i< tmp1.size();i++)printf("%d\n",tmp1[i]);
    printf("%d\n",(int)tmp.size());
    for(int i=0;i< tmp.size();i++)printf("%d %d\n",tmp[i].first,tmp[i].second);
}
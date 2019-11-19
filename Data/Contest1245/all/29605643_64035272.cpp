//
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int ,int > P;
using namespace std;
#define ll long long
#define maxnn 4010010
struct node
{
    int st,en;
    ll le;
}ed[maxnn];
ll cnt;
ll k[maxnn];
ll n;
int f[maxnn];
int gf(int v)
{
    return f[v]==v?v:f[v]=gf(f[v]);
}
bool cmp(node a,node b)
{
    return a.le<b.le;
}
queue<int > Q1;
queue<P> Q2;
ll ans=0;
void krus()
{
    for(int i=0;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=cnt;i++)
    {
        int fx=gf(ed[i].st);
        int fy=gf(ed[i].en);
        if(fx==fy) continue;
        f[fx]=fy;
        ans+=ed[i].le;
        if(ed[i].st==0)
        {
            Q1.push(ed[i].en);
            continue;
        }
        Q2.push(make_pair(ed[i].st,ed[i].en));
    }
    
}
ll x[maxnn],y[maxnn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    ll d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>d;
        ed[++cnt].st=0;
        ed[cnt].en=i;
        ed[cnt].le=d;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            ed[++cnt].st=i;
            ed[cnt].en=j;
            ed[cnt].le=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
        }
    sort(ed+1,ed+1+cnt,cmp);
    krus();
    cout<<ans<<endl;
    cout<<Q1.size()<<endl;
    while(Q1.size())
    {
        cout<<Q1.front()<<" ";
        Q1.pop();
    }
    puts(" ");
    cout<<Q2.size()<<endl;
    while(Q2.size())
    {
        cout<<Q2.front().first<< " "<<Q2.front().second<<endl;
        Q2.pop();
    }
}

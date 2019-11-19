/****************************
* Author : 水娃             *
* Date : 2019-11-01-23.07.43*
****************************/
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define mst(a,b) memset(a,b,sizeof(a))
#define ll long long
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
const int MAXN=(int)1e5+10;
const int mo=(int)1e9+7;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
using namespace std;
ll mp[2100][2100];
struct node
{
    int x,y;
}a[2100];
ll dis[2100],vis[2100],cost[2100],f[2100],n;
vector<int>v1;
vector<node>v2;
ll calcost(ll x,ll y)
{
    return (cost[x]+cost[y])*mp[x][y];
}
ll dijkstra(int id)
{
    vis[id]=1;
    v1.push_back(id);
    ll ans=dis[id];
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&calcost(i,id)<dis[i])
        {
            f[i]=id;
            dis[i]=calcost(i,id);
        }
    }
    ll minndis,minnid;
    for(int i=1;i<n;i++)
    {
        minndis=LONG_MAX;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<minndis)
            {
                minndis=dis[j];
                minnid=j;
            }
        }
        vis[minnid]=1;
        ans=ans+dis[minnid];
        if(f[minnid])v2.push_back({f[minnid],minnid});
        else v1.push_back(minnid);
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&calcost(j,minnid)<dis[j])
            {
                f[j]=minnid;
                dis[j]=calcost(j,minnid);
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mp[i][j]=mp[j][i]=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
        }
    }
    int minn=LONG_MAX,minnid=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>dis[i];
        if(dis[i]<minn)
        {
            minn=dis[i];
            minnid=i;
        }
    }
    for(int i=1;i<=n;i++)cin>>cost[i];
    cout<<dijkstra(minnid)<<"\n";
    cout<<v1.size()<<"\n";
    for(int i=0;i<v1.size();i++)cout<<v1[i]<<" \n"[i==v1.size()-1];
    cout<<v2.size()<<"\n";
    for(int i=0;i<v2.size();i++)cout<<v2[i].x<<" "<<v2[i].y<<"\n";
    return 0;
}

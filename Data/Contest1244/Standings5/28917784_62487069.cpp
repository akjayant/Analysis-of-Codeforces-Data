#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define _IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e5+9,inf=1e18,mod=1e9+7;
vector<ll>vc[N];
ll cost[4][N],n,col[N];

ll dfs(ll id,ll p,ll a,ll b,ll c,ll lv)
{
    ll ret=0;
    if(lv%3==0)
        ret=cost[a][id];
    else if(lv%3==1)
        ret=cost[b][id];
    else
        ret=cost[c][id];
    for(auto x: vc[id])
    {
        if(x==p)
            continue;
        ret+=dfs(x,id,a,b,c,lv+1);
    }
    return ret;
}

void setcol(ll id,ll p,ll a,ll b,ll c,ll lv)
{
   if(lv%3==0)
        col[id]=a;
    else if(lv%3==1)
        col[id]=b;
    else
       col[id]=c;
    for(auto x: vc[id])
    {
        if(x==p)
            continue;
        setcol(x,id,a,b,c,lv+1);
    }
}

int main()
{
    _IO;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>cost[1][i];
    for(int i=1; i<=n; i++)
        cin>>cost[2][i];
    for(int i=1; i<=n; i++)
        cin>>cost[3][i];
    for(int i=1; i<n; i++)
    {
        ll u,v;
        cin>>u>>v;
        vc[u].pb(v);
        vc[v].pb(u);
    }

    ll mx=0,cnt=0,id=-1;
    for(int i=1; i<=n; i++)
    {
        ll p=vc[i].size();
        mx=max(mx,p);
        if(vc[i].size()==1)
            id=i;
    }

    if(mx>2)
        cout<<-1<<"\n";
    else
    {
        ll mn=0,c1=1,c2=2,c3=3;
        ll x=dfs(id,id,1,2,3,0);
        mn=x;

        x=dfs(id,id,1,3,2,0);

        if(x<mn)
        {
            mn=x;
            c1=1;c2=3;c3=2;
        }
        x=dfs(id,id,2,1,3,0);
        if(x<mn)
        {
            mn=x;
            c1=2;c2=1;c3=3;
        }
        x=dfs(id,id,2,3,1,0);
        if(x<mn)
        {
            mn=x;
            c1=2;c2=3;c3=1;
        }
        x=dfs(id,id,3,2,1,0);
        if(x<mn)
        {
            mn=x;
            c1=3;c2=2;c3=1;
        }
        x=dfs(id,id,3,1,2,0);
        if(x<mn)
        {
            mn=x;
            c1=3;c2=1;c3=2;
        }
        cout<<mn<<"\n";
        setcol(id,id,c1,c2,c3,0);
        for(int i=1;i<=n;i++)cout<<col[i]<<" ";

    }


}

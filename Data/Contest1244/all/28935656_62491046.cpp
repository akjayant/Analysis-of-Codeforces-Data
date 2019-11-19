#include<bits/stdc++.h>
#define faster_io ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define mem(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
using namespace std;
const ll N=1e5+3,inf=1e18,mod=1e9+7,eps=-1e8;
ll tc,n,m,a,b,c,i,j,k,l,sum,ans,mx;
ll ar1[N],ar2[N],ar3[N],clr[N],flag[5];
string s,t;
vector<ll>v[N];

void dfs(ll node,ll par)
{
    clr[node]=(clr[par]+1)%3;
    for(auto cld:v[node])
    {
        if(clr[cld]!=-1)
            continue;
        dfs(cld,node);
        break;
    }
}

int32_t main()
{
    faster_io;
    ans=inf;
    cin>>n;
    mem(clr,-1);
    for(i=1; i<=n; i++)
        cin>>ar1[i];
    for(i=1; i<=n; i++)
        cin>>ar2[i];
    for(i=1; i<=n; i++)
        cin>>ar3[i];
    for(i=1; i<n; i++)
        cin>>a>>b,v[a].pb(b),v[b].pb(a);
    for(i=1;i<=n;i++)
        if(v[i].size()==1)
            m=i;
    dfs(m,0);
    for(i=1; i<=n; i++)
        if(clr[i]==-1)
            cout<<-1,exit(0);
    for(i=1,sum=0; i<=n; i++)
    {
        if(clr[i]==0)
            sum+=ar1[i];
        else if(clr[i]==1)
            sum+=ar2[i];
        else
            sum+=ar3[i];
    }
    if(sum<ans)
        ans=sum,flag[0]=1,flag[1]=2,flag[2]=3;

    for(i=1,sum=0; i<=n; i++)
    {
        if(clr[i]==0)
            sum+=ar1[i];
        else if(clr[i]==1)
            sum+=ar3[i];
        else
            sum+=ar2[i];
    }
    if(sum<ans)
        ans=sum,flag[0]=1,flag[1]=3,flag[2]=2;

    for(i=1,sum=0; i<=n; i++)
    {
        if(clr[i]==0)
            sum+=ar2[i];
        else if(clr[i]==1)
            sum+=ar1[i];
        else
            sum+=ar3[i];
    }
    if(sum<ans)
        ans=sum,flag[0]=2,flag[1]=1,flag[2]=3;

    for(i=1,sum=0; i<=n; i++)
    {
        if(clr[i]==0)
            sum+=ar2[i];
        else if(clr[i]==1)
            sum+=ar3[i];
        else
            sum+=ar1[i];
    }
    if(sum<ans)
        ans=sum,flag[0]=2,flag[1]=3,flag[2]=1;

    for(i=1,sum=0; i<=n; i++)
    {
        if(clr[i]==0)
            sum+=ar3[i];
        else if(clr[i]==1)
            sum+=ar1[i];
        else
            sum+=ar2[i];
    }
    if(sum<ans)
        ans=sum,flag[0]=3,flag[1]=1,flag[2]=2;

    for(i=1,sum=0; i<=n; i++)
    {
        if(clr[i]==0)
            sum+=ar3[i];
        else if(clr[i]==1)
            sum+=ar2[i];
        else
            sum+=ar1[i];
    }
    if(sum<ans)
        ans=sum,flag[0]=3,flag[1]=2,flag[2]=1;

    cout<<ans<<endl;
    for(i=1; i<=n; i++)
        cout<<flag[clr[i]]<<' ';
}
/*
5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2
2 3
3 4
4 5
*/

#include<bits/stdc++.h>
#include <time.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define PI acos(-1)
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define el endl
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define sz size()
#define s(x) sort(x.begin(),x.end())
#define rs(x) sort(x.rbegin(),x.rend())
#define all(v) v.begin(),v.end()
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define mod 1000000007
ll C,res;
void dfs(ll r,vector<vector<ll> > &v,vector<ll> &vis,ll a,ll b,vector<vector<ll> > &cost,vector<ll> &ans)
{
    ll i,c;
    vis[r]=1;
    for(i=0;i<3;i++)
    if(i!=a && i!=b)
    break;
    c=i;
    ans[r]=c;
    C+=cost[r][i];
    for(i=0;i<v[r].sz;i++)
    if(!vis[v[r][i]])
    dfs(v[r][i],v,vis,b,c,cost,ans);
}
int main()
{
    FAST;
    res=INF;
    ll n,i,a,b,s,sc,ssc,j;
    cin>>n;
    vector<vector<ll> > v(n+1),cost(n+1,vector<ll>(3));
    for(i=1;i<=n;i++)
    cin>>cost[i][0];
    for(i=1;i<=n;i++)
    cin>>cost[i][1];
    for(i=1;i<=n;i++)
    cin>>cost[i][2];
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(i=1;i<=n;i++)
    if(v[i].sz>=3)
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;i++)
    if(v[i].sz==1)
    {
        s=i;
        break;
    }
    vector<ll> dp(6),vis(n+1),ans(n+1);
    vector<pair<ll,ll> > m(6);
    m[0]=mp(0,1);
    m[1]=mp(0,2);
    m[2]=mp(1,0);
    m[3]=mp(1,2);
    m[4]=mp(2,0);
    m[5]=mp(2,1);
    if(v[v[s][0]][0]==s)
    ssc=v[v[s][0]][1];
    else
    ssc=v[v[s][0]][0];
    for(i=0;i<6;i++)
    {
        C=cost[s][m[i].ff]+cost[v[s][0]][m[i].ss];
        vis[s]=1,vis[v[s][0]]=1;
        dfs(ssc,v,vis,m[i].ff,m[i].ss,cost,ans);
        if(C<res)
        {
            res=C;
            sc=i;
        }
        for(j=1;j<=n;j++)
        vis[j]=0;
    }
    cout<<res<<el;
    ans[s]=m[sc].ff;
    ans[v[s][0]]=m[sc].ss;
     vis[s]=1,vis[v[s][0]]=1;
    dfs(ssc,v,vis,m[sc].ff,m[sc].ss,cost,ans);
    for(i=1;i<=n;i++)
    cout<<ans[i]+1<<" ";
}

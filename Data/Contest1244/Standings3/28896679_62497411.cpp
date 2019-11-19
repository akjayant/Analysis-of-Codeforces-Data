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
    ll n,k,i,c,j;
    cin>>n>>k;
    vector<ll> v(n+1);
    vector<pair<ll,ll> > ans;
    for(i=1;i<=n;i++)
    cin>>v[i];
    s(v);
    for(i=1,c=1;i<n;i++)
    {
        if(v[i]!=v[i+1])
        {
            ans.pb(mp(v[i],c));
            c=1;
        }
        else
        c++;
    }
    ans.pb(mp(v[i],c));
    for(i=0,j=ans.sz-1;j-i+1>1 && k>0;)
    {
        if(ans[i].ss<=ans[j].ss)
        {
            if(k<(ans[i+1].ff-ans[i].ff)*ans[i].ss)
            {
                ans[i].ff+=k/ans[i].ss;
                break;
            }
            k-=(ans[i+1].ff-ans[i].ff)*ans[i].ss;
            ans[i+1].ss+=ans[i].ss;
            i++;
        }
        else
        {
            if(k<(ans[j].ff-ans[j-1].ff)*ans[j].ss)
            {
                ans[j].ff-=k/ans[j].ss;
                break;
            }
            k-=(ans[j].ff-ans[j-1].ff)*ans[j].ss;
            ans[j-1].ss+=ans[j].ss;
            j--;
        }
    }
    cout<<ans[j].ff-ans[i].ff;
}

/* winners never quit and quitters never win.
      #swap                                 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#pragma GCC optimize ("-O3")
#define mod 1000000007
#define inf 1000000000000000000
#define rk 256
#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
struct vertex
{
    vc<ll> adj;
    ll vis=0;
    vc<ll> col;
    ll low=-1;
};
vc<ll> eu;
void dfs(vertex x[],ll sor)
{
    x[sor].vis=1;
    eu.pb(sor);
    for(auto y:x[sor].adj)
    {
        if(!x[y].vis)
        {
            dfs(x,y);
        }
    }
}
ll solve(vertex x[],ll p1,ll p2,ll p3)
{
    ll y[3]={p1,p2,p3};
    ll ans=0;
    for(ll a=0;a<eu.size();a++)
    {
        ans+=x[eu[a]].col[y[a%3]];
    }
    return ans;
}
void assign(vertex x[],ll p1,ll p2,ll p3)
{
    ll y[3]={p1,p2,p3};
    for(ll a=0;a<eu.size();a++)
    {
        x[eu[a]].low=y[a%3]+1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    vertex x[n];
    for(ll a=0;a<3;a++)
    {
        for(ll b=0;b<n;b++)
        {
            ll c;
            cin>>c;
            x[b].col.pb(c);
        }
    }
    for(ll a=0;a<n-1;a++)
    {
        ll u,v;
        cin>>u>>v;
        u--,v--;
        x[u].adj.pb(v);
        x[v].adj.pb(u);
    }
    ll sor=-1;
    for(ll a=0;a<n;a++)
    {
        if(x[a].adj.size()==1)
            sor=a;
        if(x[a].adj.size()>2){
            sor=-1;
            break;
        }
    }
    if(sor==-1)
    {
        cout<<sor<<endl;
    }
    else
    {
        dfs(x,sor);
        ll ans=solve(x,0,1,2);
        assign(x,0,1,2);
        if(ans>solve(x,0,2,1)){
            ans=solve(x,0,2,1);
            assign(x,0,2,1);
        }
        if(ans>solve(x,1,2,0)){
            ans=solve(x,1,2,0);
            assign(x,1,2,0);
        }
        if(ans>solve(x,1,0,2)){
            ans=solve(x,1,0,2);
            assign(x,1,0,2);
        }
        if(ans>solve(x,2,0,1)){
            ans=solve(x,2,0,1);
            assign(x,2,0,1);
        }
        if(ans>solve(x,2,1,0)){
            ans=solve(x,2,1,0);
            assign(x,2,1,0);
        }
        cout<<ans<<endl;
        for(ll a=0;a<n;a++)
            cout<<x[a].low<<" ";
        cout<<endl;
    }
	return 0;
}
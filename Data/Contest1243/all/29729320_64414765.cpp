/*
    STARK_BOY
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
typedef pair<ll,ll> pii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define INF 1000000000  
#define MOD 1000000007
#define MO 1000000006
#define M 998244353
#define PI           3.14159265358979323846  /* pi */
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
ll modExpo(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modExpo((x*x)%MOD,n/2);
    else                             //n is odd
        
        return (x*modExpo((x*x)%MOD,(n-1)/2))%MOD;

}
ll modInverse(ll n) 
{ 
    return modExpo(n,MOD-2); 
}
#define N 1000005
//Variables Start   
ll n,m,k,ar[N],br[N];
string s,s1;
set<ll> adj[100005];
set<ll> se;
vi z;
//Variables End
ll sub(ll a, ll b){return (a-b+MOD)%MOD;}
ll add(ll a, ll b){return (a+b)%MOD;}
ll mul(ll a, ll b){return (a*b)%MOD;}

ll dfs(ll i){
    int ret=1;
    for (auto it=se.begin();it!=se.end();)
    {
        if (adj[i].count(*it)==0) 
        {
            
            ll x=*it;
            //dd
            se.erase(x);
            
            ret+=dfs(x);
            it=se.lower_bound(x);
        } 
        else 
            it++;
    }
    return ret;
}


int main()
{
    ios
    int ti=1;
    //cin>>ti;
    while(ti--)
    {
        cin>>n>>m;
        rep(i,0,m)
        {
            ll x, y;
            cin>>x>>y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        rep(i,1,n+1)se.insert(i);
        while(se.size())
        {
            ll x = *se.begin();
            se.erase(x);
            z.push_back(dfs(x));
        }
        cout<<z.size()-1<<endl;        
    }
    return 0;
        
}
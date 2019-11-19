//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT
 
#include<bits/stdc++.h>
using namespace std;
 
#define INF LONG_LONG_MAX
#define MINF LONG_LONG_MIN
#define pi acos(-1)
#define bp __builtin_popcount
#define ll long long int
#define ld long double
#define pii pair<ll,ll>
#define For(i,a,b) for(ll i=a;i<b;i++)
#define Fori(i,a,b,p) for(ll i=a;i<b;i+=p)
#define Ror(i,a,b) for(ll i=a;i>b;i--)
#define Rori(i,a,b,p) for(ll i=a;i>b;i-=p)
 
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<ll,vector<ll>,greater<ll> > 
#define maxQueue priority_queue<ll> 
 
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL))
 
const ll nax = 1e5+5;
map<pii,bool> m;
set <ll> s;
ll conn = 0;
void dfs(ll v)
{
    vector<ll> g;
    for (auto it : s) if(m.find({v,it}) == m.end()) g.pb(it);
    for (auto it : g) s.erase(s.find(it));
    for (auto it : g) dfs(it);
    return ;
}
int main()
{
    FAST;
    ll n , mm;
    cin >> n >> mm;
    For(i,1,n+1)    s.insert(i);
    For(i,0,mm)
    {
        ll u , v;
        cin >> u >> v;
        m[{u,v}] = m[{v,u}] = 1;
    }
    for( ll i=1 ; i <= n ; i++ )
    {
        if( s.find( i ) != s.end() )
        {
            s.erase(i);
            dfs(i);
            conn++;
        }
    }
    cout << conn-1;
}
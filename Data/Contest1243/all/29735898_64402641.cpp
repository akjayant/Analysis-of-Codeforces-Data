//Utkarsh.25dec
#include <bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
const int N=500023;
bool vis[N];
vector <int> adj[N];
void solve()
{
    ll n,m;
    cin>>n>>m;
    map <pair<ll,ll>,ll> isedge;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        isedge[mp(a,b)]=1;
        isedge[mp(b,a)]=1;
    }
    ll ans=0;
    set <ll> s;
    for(int i=1;i<=n;i++)
        s.insert(i);
    queue <int> q;
    q.push(1);
    s.erase(1);
    while(true)
    {
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            vl v;
            for(auto it=s.begin();it!=s.end();it++)
            {
                ll b=(*it);
                if(isedge[mp(a,b)]==0)
                {
                    q.push(b);
                    v.pb(b);
                }
            }
            for(int i:v)
                s.erase(i);
        }
        if(s.size()==0)
            break;
        ll a=(*s.begin());
        q.push(a);
        ans++;    
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
}
#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=200010;

vector<ll> adj[N];

set<ll> leftnode;

void bfs(ll node)
{
    queue<ll> q;
    q.push(node);
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        vector<ll> toremove;
        for(auto u:leftnode)
        {
            if(!binary_search(adj[v].begin(),adj[v].end(),u))
            {
                q.push(u);
                toremove.pb(u);
            }
        }
        for(ll i=0;i<toremove.size();++i)
        {
            leftnode.erase(toremove[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;++i)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(ll i=1;i<=n;++i){leftnode.insert(i);sort(adj[i].begin(),adj[i].end());}
    ll ans=0;

    while(!leftnode.empty())
    {
        ++ans;
        ll node=*leftnode.begin();
        leftnode.erase(leftnode.begin());
        bfs(node);
    }

    cout<<ans-1<<endl;

    return (0);
}

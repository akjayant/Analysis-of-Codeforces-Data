#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); \
                      cerr << "\n\n" << "Time elapsed: " << \
                      (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
                      return 0
#define ll long long int
#define ull unsigned long long int
#define db long double
#define ff first
#define ss second
#define MP make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pii pair<int , int>
#define pdd pair<db , db>
#define pll pair<ll , ll>
#define vpl vector<pll >
#define vll vector<ll >
#define mod 1000000007
#define mod1 998244353
#define inf 4000000000000000007
#define eps 0.000001
#define stp fixed<<setprecision(20)
#define endl '\n'
#define codejam 0

const ll N=100005;
ll c[N][3],ans[N];
vll adj[N],v;

void dfs(ll x,ll pr)
{
    v.pb(x);
    for(auto i:adj[x])
        if(i!=pr)
            dfs(i,x);
}

void solve()
{
    ll n;cin>>n;
    for(ll i=0;i<3;i++)
        for(ll j=1;j<=n;j++)
            cin>>c[j][i];

    for(ll i=2;i<=n;i++)
    {
        ll x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll root=1;
    for(ll i=1;i<=n;i++)
    {
        if(adj[i].size()>2)
        {
            cout<<-1;
            return;
        }
        if(adj[i].size()==1)
            root=i;
    }
    dfs(root,root);

    ll a[3]={0,1,2};
    ll val=inf;
    do
    {   
        ll sum=0;
        for(ll i=0;i<n;i++)
            sum+=c[v[i]][a[i%3]];

        if(sum<val)
        {
            val=sum;
            for(ll i=0;i<n;i++)
                ans[v[i]]=a[i%3];
        }
    }
    while(next_permutation(a,a+3));

    cout<<val<<endl;
    for(ll i=1;i<=n;i++)
        cout<<ans[i]+1<<" ";    
}

int main()
{
    fastio;
    #ifdef APNA_IO
        start_routine();
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif

    ll t=1;
    // cin>>t;
    for(ll i=1;i<=t;i++)
    {
        if(codejam) cout<<"Case #"<<i<<": ";
        solve();
    }

    #ifdef APNA_IO
        end_routine();
    #endif
}

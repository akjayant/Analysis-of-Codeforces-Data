#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll          long long
#define pb          push_back
#define eb 			emplace_back
#define mp 			make_pair
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define fi          first
#define si          second
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define checkbit(n, b) ((n >> b) & 1)
#define mod        1000000007
#define puts(n)		cout<<n;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define setbits(x) __builtin_popcount(x)
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
ll posx[]={1,-1,0,0};
ll posy[]={0,0,1,-1};

void solve()
{
    ll n,i;
    cin>>n;
    ll x[n],y[n];
    for(i=0;i<n;i++)
    cin>>x[i]>>y[i];
    ll c[n],k[n];
    ll ar[n];
    priority_queue<pair<ll,ll> >q;
    vi v;
    for(i=0;i<n;i++)
    {
        cin>>c[i];
        ar[i]=c[i];
        q.push(mp(-c[i],i));
    }
    for(i=0;i<n;i++)
    cin>>k[i];
    bool vis[n];
    ll ans=0;
    memset(vis,0,sizeof(vis));
    ll par[n];
    mset(par,-1);
    while(!q.empty())
    {
        pair<ll,ll>p=q.top();
        q.pop();
        if(vis[p.second]==1)
        {
            continue;
        }
        ans-=p.fi;
        vis[p.si]=1;
        for(i=0;i<n;i++)
        {
            if(vis[i]==1)
            continue;
            ll r=abs(x[i]-x[p.si])+abs(y[i]-y[p.si]);
            if(ar[i]>r*(k[i]+k[p.si]))
            {
                ar[i]=r*(k[i]+k[p.si]);
                par[i]=p.si;
                q.push(mp(-r*(k[i]+k[p.si]),i));
            }
        }
    }
    cout<<ans<<endl;
    ll cnt=0;
    for(i=0;i<n;i++)
    {
        if(par[i]==-1)
        cnt++;
    }
    cout<<cnt<<endl;
    for(i=0;i<n;i++)
    {
        if(par[i]==-1)
        cout<<i+1<<" ";
    }
    cout<<endl;
    ll r=(n-cnt);
    cout<<r<<endl;
    for(i=0;i<n;i++)
    {
        if(par[i]!=-1)
        cout<<i+1<<" "<<par[i]+1<<endl;
    }
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

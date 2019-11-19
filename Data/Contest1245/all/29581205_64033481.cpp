#include<bits/stdc++.h>
#define ll long long
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 2005;

ll modexp(ll x, ll n)
{
    if(n==0)
        return 1LL;
    if(n%2==0)
    {
        ll y = modexp(x,n/2)%mod;
        return (y*y)%mod;
    }
    return (x*modexp(x,n-1)%mod)%mod;
}

ll powr(ll x, ll n)
{
    ll ans = 1;
    for(int i=1;i<=n;i++)
        ans=ans*x;
    return ans;
}

bool power[MAX];

vector<pair<int,int> > conn;

int par[MAX];

int dp[MAX];

bool visited[MAX];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    si(n);
    for(int i=0;i<n;i++)
        par[i] = -1;
    ll x[n],y[n],c[n],k[n];
    pair<ll,ll> p[n];
    for(int i=0;i<n;i++)
    {
        sl(x[i]),sl(y[i]);
    }
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        sl(c[i]);
        ans = ans + c[i];
        power[i] = 1;
        p[i] = mp(c[i],i);
        dp[i] = c[i];
    }
    for(int i=0;i<n;i++)
        sl(k[i]);
    sort(p,p+n);
    int done = 0;
    //reverse(p,p+n);
    priority_queue<pair<ll,int>,vector<pair<ll,int> >, greater<pair<ll,int> > >pq;
    for(int i=0;i<n;i++)
    {
        pq.push(p[i]);
    }
    while(!pq.empty())
    {
        ll currpow = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(currpow>dp[curr]||visited[curr]==1)
            continue;
        visited[curr] = 1;
        for(int i=0;i<n;i++)
        {
            if(i==curr)
                continue;
            if(visited[i]==1)
                continue;
            ll d = abs(x[i]-x[curr]) + abs(y[i]-y[curr]);
            ll cost = d*(k[i]+k[curr]);
            if(dp[i]>cost)
            {
                dp[i] = cost;
                pq.push(mp(dp[i],i));
                par[i] = curr;
            }
        }
    }
    int v = 0;
    for(int i=0;i<n;i++)
    {
        if(par[i]==-1)
            v++;
        else
        {
            int curr = par[i];
            ll d = abs(x[i]-x[curr]) + abs(y[i]-y[curr]);
            ll cost = d*(k[i]+k[curr]);
            ans = ans - c[i] + cost;
        }
    }
    pfl(ans);
    pfi(v);
    for(int i=0;i<n;i++)
    {
        if(par[i]==-1)
            pf("%d ",i+1);
    }
    pf("\n");
    pf("%d\n",n-v);
    for(int i=0;i<n;i++)
    {
        if(par[i]!=-1)
        {
            pf("%d %d\n",i+1,par[i]+1);
        }
    }
    return 0;
}
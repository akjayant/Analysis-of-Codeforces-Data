/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define pf          printf
#define sf          scanf
#define ff          first
#define ss          second
#define clr         clear()
#define sz          size()
#define pb          push_back
#define mk          make_pair
#define pi          acos(-1)
#define inf         100000000000000000
#define mod         1000000009
#define ull         unsigned long long int
#define f(i,k,n)    for(ll i=k;i<n;i++)
#define fr(i,n,k)   for(i=n;i>=k;i--)
#define ent(a)      scanf("%lld",&a)
#define ent2(a,b)   scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a)      memset(a,0,sizeof(a))
#define vec(v,s)    vector<ll>v[s]
#define arr(a,s)    ll a[s];
//#define check(n,pos) (n&(1<<pos))
//#define set(n,pos)  (n|(1<<pos))
//knight and king//
int dr[]= {2, 2, -2, -2, 1, -1, 1, -1};
int dc[]= {1,-1,  1, -1, 2,  2,-2, -2};
int dr1[]= {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[]= {-1,0, 1,-1, 0, 1, -1, 0,   1};
int dr2[]= {0, 0, 1, -1};
int dc2[]= {1,-1, 0,  0};
////////////////////////////
#define ma 1000006
using namespace std;


vector<ll>adj[ma];

ll s=0,b[ma];
ll a[4][ma];
ll dp[ma][4][4];
ll b1[ma];
void dfs(ll u,ll par)
{
    b[++s]=u;
    ll i,j;

    for(i=0;i<adj[u].sz;i++)
    {
        ll p=adj[u][i];
        if(p==par)continue;
        dfs(p,u);
    }
}

ll cal(ll x,ll f,ll f1)
{
    if(x>s)return 0;
    ll &r=dp[x][f][f1];
    if(r!=-1)return r;
    r=inf;
    ll i;

    for(i=1;i<=3;i++)
    {
        if(i==f||i==f1)continue;
        ll r1=cal(x+1,i,f)+a[i][b[x]];
        r=min(r,r1);
    }
    return r;
}

void prin(ll x,ll f,ll f1)
{
    if(x>s)return;

    ll i,j;

    for(i=1;i<=3;i++)
    {
        if(i==f||i==f1)continue;
        ll r=cal(x+1,i,f)+a[i][b[x]];
        if(r==dp[x][f][f1])
        {
            b1[b[x]]=i;
            prin(x+1,i,f);
            return;

        }
    }
}

int main()
{
    ll n,i,j,u,v;
    while(cin>>n)
    {
      for(i=1;i<=3;i++)
      {
          for(j=1;j<=n;j++)cin>>a[i][j];
      }

        for(i=1;i<n;i++)
        {
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ll cn=0,r=1;
        for(i=1;i<=n;i++)
        {
            if(adj[i].sz>2)
            {
                cout<<"-1"<<endl;
                return 0;
            }
            if(adj[i].sz==1)r=i;
        }
        memset(dp,-1,sizeof(dp));
        dfs(r,-1);

        ll ans=cal(1,0,0);
        prin(1,0,0);
        cout<<ans<<endl;
        for(i=1;i<=n;i++)cout<<b1[i]<<" ";
        cout<<endl;




    }
}

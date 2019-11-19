#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define bitcount __builtin_popcountll
#define mod 1000000007
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define s(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define all(v) v.begin(),v.end()
#define p(x) printf("%d ",x)
#define pll(x) printf("%lld",x)
#define pend printf("\n")
#define debug(x) cout << "> " << #x << " : " << x << "\n";
#define gur_chella ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 100005  
#define LN 18
#define infinity 4123456789123456789ll
#define CMOD 998244353
#define pall pair<ll,ll>
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
ll powfi(ll x, ll y, ll p)
{
    ll ans = 1;
    x%=p;
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans%p)*(x%p))%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}
ll power(ll x, ll y)
{
    ll ans = 1;
   // x%=p;
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans)*(x));
        y = y>>1;
        x = (x*x);
    }
    return ans;
}
const ll Random = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(int x) const { return (x ^ Random); }
};
#define ht gp_hash_table<int, int, chash>
// void init()
// {
//  for(int i=0;i<2002;i++)
//  {
//      for(int j=0;j<2002;j++)
//      {
//          if(j==0 || j==i)
//              ncr[i][j]=1;
//          else if(j>i)
//              ncr[i][j]=0;
//          else
//              ncr[i][j]=((ncr[i-1][j-1]%CMOD) + (ncr[i-1][j] % CMOD) )%CMOD;
//      }
//  }
// }
// inline int scan()
// {
//     char c = getchar_unlocked();
//     int x = 0;
//     while(c<'0'||c>'9'){
//         c=getchar_unlocked();
//     }
//     while(c>='0'&&c<='9'){
//         x=(x<<1)+(x<<3)+c-'0';
//         c=getchar_unlocked();
//     }
//     return x;
// }
// ------------------End of Template-------------//
#define int long long
struct edge
{
    int from, to, weight;
};
int r[2050],sz[2050],n;
void init(int n)
{
    for(int i=0;i<n;++i)
    {
        r[i]=i;
        sz[i]=1;
    }
}
int root(int x)
{
    while(x!=r[x])
    {
        r[x]=r[r[x]];
        x=r[x];
    }
    return x;
}
void uni(int a, int b)
{
    int ra = root(a),rb=root(b);
    if(ra!=rb)
    {
        if(sz[ra]<sz[rb])
        {
            sz[rb]+=sz[ra];
            r[ra]=r[rb];
        }
        else
        {
            sz[ra]+=sz[rb];
            r[rb]=r[ra];
        }
    }
}
bool comp(edge lhs, edge rhs)
{
    return lhs.weight<rhs.weight;
}
vector<edge>edges;
vector<edge>ans;
pii cities[2050];
int cost[2050], kk[2050];
int f(int c1, int c2)
{
    pii city1 = cities[c1],city2 = cities[c2];
    int co = (abs(city1.fi - city2.fi) + abs(city1.se - city2.se))*(kk[c1] + kk[c2]);
    return co;
}
signed main()
{
    gur_chella
    int i, j,k;
    int T=1;
    //cin>>T;
    while(T--)
    {
        cin>>n;
        pii mincost = {infinity, 1};
        for(i=0;i<n;++i)
        {
            cin>>cities[i].fi>>cities[i].se;
        }
        for(i=0;i<n;++i)
        {
            cin>>cost[i];
        }
        for(i=0;i<n;++i)
            cin>>kk[i];
        for(i=0;i<n;++i)
        {
            for(j=i+1;j<n;++j)
            {
                edges.pb({i,j,f(i,j)});
            }
        }
        int aux = n;
        init(n+1);
        for(i=0;i<n;++i)
        {
            edges.pb({i,n,cost[i]});
        }
        sort(all(edges),comp);
        int fincost=0;
        // for(i=0;i<edges.size();++i)
        //     cout<<edges[i].from<<" "<<edges[i].to<<" "<<edges[i].weight<<"\n";
        for(i=0;i<edges.size();++i)
        {
            if(root(edges[i].from)!=root(edges[i].to))
            {
                uni(edges[i].from,edges[i].to);
                //cout<<edges[i].from<<" "<<edges[i].to<<"ok\n";
                fincost+=edges[i].weight;
                ans.pb({edges[i].from,edges[i].to,edges[i].weight});

            }
        }
        cout<<fincost<<"\n";
        int cc=0;
        for(i=0;i<ans.size();++i)
        {
            if( ans[i].to==n)
            {
                cc++;
            }
        }
        cout<<cc<<"\n";
        for(i=0;i<ans.size();++i)
        {
            if(ans[i].to==n)
                cout<<ans[i].from+1<<" ";
        }
        cout<<"\n";
        cout<<ans.size()-cc<<"\n";
        for(i=0;i<ans.size();++i)
        {
            if(ans[i].to!=n)
                cout<<ans[i].from+1<<" "<<ans[i].to+1<<"\n";
        }

    }
    
       
}
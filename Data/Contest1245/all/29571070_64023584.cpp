#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int pr[2001],sz[2001],mn[2001],c[2001],k[2001],x[2001],y[2001];

void init(int n)
{
    for(int i=1;i<=n;++i)
        pr[i]=i,sz[i]=1,mn[i]=c[i];
}

int rt(int i)
{
    if(pr[i]==i)
        return i;

    return pr[i] = rt(pr[pr[i]]);
}

int cst(int i,int j)
{
    int dst = abs(x[i]-x[j]) + abs(y[i]-y[j]);
    int per = k[i]+k[j];

    return per*dst;
}

bool cmp(pii a,pii b)
{
    return cst(a.ff,a.ss) < cst(b.ff,b.ss);
}

bool un(int i,int j)
{
    int u = rt(i);
    int v = rt(j);

    if(u==v)
        return 0;

    if(mn[u]+mn[v] < min(mn[u],mn[v]) + cst(i,j))
        return 0;

    if(sz[u]<sz[v])
        swap(u,v);

    pr[v]=u;
    sz[u] += sz[v];
    mn[u] = min(mn[u],mn[v]);

    return 1;
}

int32_t main()
{
    c_p_c();
    int n; cin>>n;

    vector<pii> v;

    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            v.pb({i,j});

    for(int i=1;i<=n;++i)
        cin>>x[i]>>y[i];

    for(int i=1;i<=n;++i)
        cin>>c[i];

    for(int i=1;i<=n;++i)
        cin>>k[i];

    init(n);

    sort(v.begin(), v.end(),cmp);

    vector<pii> edg;

    for(auto el : v)
    {
        bool dn = un(el.ff,el.ss);

        if(dn)
            edg.pb({el.ff,el.ss});
    }

    int gp=0;

    for(int i=1;i<=n;++i)
        if(rt(i)==i)
            gp++;

    
    vector<bool> visit(n+1,0);

    int min_c = 0;

    for(int i=1;i<=n;++i)
        if(rt(i)==i)
        {
            min_c += mn[i];
        }

    for(auto el : edg)
        min_c += cst(el.ff,el.ss);

    cout << min_c << '\n';
    cout<<gp<<'\n';

    for(int i=1;i<=n;++i)
        if(!visit[rt(i)] && mn[rt(i)]==c[i])
        {
            cout<<i<<' ';
            visit[rt(i)]=1;
        }

    cout<<'\n';

    cout<<edg.size()<<'\n';

    for(auto p : edg)
        cout<<p.ff<<' '<<p.ss<<'\n';
    return 0;
}
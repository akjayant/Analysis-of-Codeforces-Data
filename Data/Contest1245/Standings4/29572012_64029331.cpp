/*enjoy karo yaar*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

#define pii pair<int,int>

const int inf=1e18,M=1e9+7;
const int N=2e3+5;

vector<pair<int,pii>> edges;
vector<pii> v(N);
vector<int> c(N),k(N),elec(N,0);
vector<int> arr(N),siz(N);

vector<int> one;
vector<pii> two;

int cost=0;
int mn,fl,pos;

//vector<int> adj[N],vis(N,0);

void init(int n)
{
	int i;
	for(i=1;i<=n;++i)
		arr[i]=i,siz[i]=1;
}

int root(int x)
{
	while(arr[x]!=x)
	{
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
	return x;
}

void kruskal()
{
    int a,b,x,y;
    for(auto c:edges)
    {
        //cout<<"\n";
        //cout<<c.F<<" "<<c.S.F<<" "<<c.S.S<<"\n";

        a=c.S.F;
        b=c.S.S;

        x=root(a);
        y=root(b);

        if(a==b && !elec[x])
        {
            cost+=c.F;
            one.pb(a);
            elec[x]=1;
            continue;
        }

        if(x!=y && !(elec[x] && elec[y]))
        {
            //cout<<a<<" "<<b<<"\n";

            cost+=c.F;

            if(siz[x]<siz[y])
                swap(x,y);
            arr[y]=x;
            siz[x]+=siz[y];
            siz[y]=0ll;

            if(elec[x] || elec[y])
                elec[x]=elec[y]=1;

            two.pb({a,b});

            //cout<<a<<" "<<b<<"\n";
            //adj[a].pb(b);
            //adj[b].pb(a);
        }
    }
}

int dist(int x,int y)
{
    return (abs(v[x].F-v[y].F)+abs(v[x].S-v[y].S));
}

/*void dfs(int x)
{
    vis[x]=1;

    if(elec[x])
        fl=1;

    if(c[x]<mn)
    {
        mn=c[x];
        pos=x;
    }

    for(auto u:adj[x])
    {
        //cout<<u<<" "<<vis[u]<<"\n";
        if(!vis[u])
            dfs(u);
    }
}*/

void solve()
{
    int n;
    cin>>n;

    init(n);

    for(int i=1;i<=n;++i)
        cin>>v[i].F>>v[i].S;

    for(int i=1;i<=n;++i)
        cin>>c[i];

    for(int i=1;i<=n;++i)
        cin>>k[i];

    int tmp;
    for(int i=1;i<=n;++i)
    {
        edges.pb({c[i],{i,i}});

        for(int j=1;j<=n;++j)
        {
            if(i!=j)
            {
                tmp=dist(i,j)*(k[i]+k[j]);
                edges.pb({tmp,{i,j}});
            }
        }
    }

    sort(all(edges));

    kruskal();

    /*if(two.size())
    {
        for(int i=1;i<=n;++i)
        {
            if(!vis[i])
            {
                fl=0;
                pos=i;
                mn=c[i];

                //cout<<i<<" "<<adj[i].size()<<"\n";

                dfs(i);

                if(!fl)
                {
                    cost+=mn;
                    one.pb(pos);
                }
            }
        }
    }*/

    cout<<cost<<"\n";

    cout<<one.size()<<"\n";
    for(auto c:one)
        cout<<c<<" ";
    cout<<"\n";

    cout<<two.size()<<"\n";
    for(auto c:two)
        cout<<c.F<<" "<<c.S<<"\n";
    cout<<"\n";
}

int32_t main()
{
    //fast();

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}


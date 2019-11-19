#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define all(a) a.begin(),a.end()
#define ull unsigned long long
#define endl '\n'
#define y1 yaumru
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define iter vector<int>::iterator
#define int long long
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

template<class T>
using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd1(chrono::steady_clock::now().time_since_epoch().count());

//find_by_order
//order_of_key

const int N=3e5+7;
const int inf=1e18+5;
const int mod=1e9+7;
const ld eps=1e-9;

int p[N];
int sz[N],best[N];
int x[N],y[N],c[N],k[N];
int sum[N];
bool used[N];

int get(int v)
{
    if (v==p[v])return v;
    p[v]=get(p[v]);
    return p[v];
}

void unite(int a,int b,int cost)
{
    a=get(a);
    b=get(b);
    if (sz[a]<sz[b]){
        swap(a,b);
    }
    p[b]=a;
    sz[a]+=sz[b];
    sum[a]+=sum[b];
    sum[a]+=cost;
    if (c[best[b]]<c[best[a]]){
        best[a]=best[b];
    }
}

main ()
{
    ios;
    int n;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
    }
    for (int i=1;i<=n;++i){
        cin>>c[i];
    }
    for (int i=1;i<=n;++i){
        cin>>k[i];
    }
    for (int i=1;i<=n;++i){
        p[i]=i;
        sz[i]=1;
        best[i]=i;
    }
    vector< pair<int,pair<int,int> > >f;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            int cost=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
            f.pb({cost,{i,j}});
        }
    }
    sort(all(f));
    int ans=0;
    vector< pair<int,int> >res;
    for (int i=0;i<f.size();++i){
        int x=f[i].ss.ff;
        int y=f[i].ss.ss;
        int cost=f[i].ff;
        if (get(x)!=get(y)){
            int a=get(x);
            int b=get(y);
            int pos=best[a];
            if (c[best[b]]<c[pos]){
                pos=best[b];
            }
            if (sum[a]+sum[b]+cost+c[pos]<=sum[a]+sum[b]+c[best[a]]+c[best[b]]){
                ans+=cost;
                res.pb({x,y});
                unite(x,y,cost);
            }
        }
    }
    vector<int>vec;
    for (int i=1;i<=n;++i){
        int a=get(i);
        if (!used[best[a]]){
            used[best[a]]=true;
            vec.pb(best[a]);
            ans+=c[best[a]];
        }
    }
    cout<<ans<<endl;
    cout<<(int)vec.size()<<endl;
    for (int i=0;i<vec.size();++i){
        cout<<vec[i]<<' ';
    }
    cout<<endl;
    cout<<(int)res.size()<<endl;
    for (int i=0;i<res.size();++i){
        cout<<res[i].ff<<' '<<res[i].ss<<endl;
    }
}

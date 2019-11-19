#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mod1 998244353
#define inf1 INT_MAX
#define inf2 LLONG_MAX
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define sbit __builtin_popcount
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define rit(it,x) for(auto it=x.begin();it!=x.end();it++)
#define cases(t) int t; cin>>t; rep(casn,1,t+1)
#define fill(a,b) memset(a,b,sizeof(a))
#define dbg(x) cerr<<#x<<" "<<x<<endl;
#define dbga(arr,n) cerr<<#arr<<": "; rep(tt,0,n)cerr<<arr[tt]<<" "; cerr<<endl;
#define infile ifstream fin; fin.open("input.txt")
#define outfile ofstream fout; fout.open("output.txt")
#define vec vector<int>
#define pii pair<int,int>
#define plii pair<ll,int>
#define pll pair<ll,ll>
#define p_queue priority_queue< plii,vector< plii >,greater< plii > > 
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%lld",&x)
#define sst(x) scanf("%s",x)
#define pl(x) printf("%lld\n",x)
#define pi(x) printf("%d\n",x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mex 100005
vec adj[mex];
int vis[mex];

inline ll binex(ll a,ll b)
{
    ll ans=1,temp=a%mod;
    while(b!=0){
        if(b&1) ans=(ans*temp)%mod;
        temp=(temp*temp)%mod;
        b=b>>1;
    }
    return ans;
}

inline void dfs(int u,vec& v)
{
    vis[u]=1; v.pb(u);
    rep(i,0,sz(adj[u])){
        int x=adj[u][i];
        if(!vis[x]) dfs(x,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    ll mat[3][n];
    rep(i,0,3){
        rep(j,0,n) cin>>mat[i][j];
    }
    rep(i,0,n-1){
        int u,v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int s;
    rep(i,0,n){
        if(sz(adj[i])>2){
            cout<<-1<<endl;
            return 0;
        }
        if(sz(adj[i])==1) s=i;
    }
    vec v; dfs(s,v);   //dbga(v,sz(v));
    int aux[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,1,0},{2,0,1}};
    ll ans=inf2,idx=-1;
    rep(i,0,6){
        ll x=0;
        rep(j,0,sz(v)) x+=mat[aux[i][j%3]][v[j]];
        if(x<ans){
            ans=x;
            idx=i;
        }
    }
    cout<<ans<<endl;
    int xp[n];
    rep(i,0,n) xp[v[i]]=aux[idx][i%3];
    rep(i,0,n) cout<<xp[i]+1<<" "; cout<<endl;
}
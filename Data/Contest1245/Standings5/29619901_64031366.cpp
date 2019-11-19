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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    pii arr[n];
    rep(i,0,n){
        int l,r; cin>>l>>r;
        arr[i]=mp(l,r);
    }
    ll c[n],k[n],par[n];
    rep(i,0,n) cin>>c[i];
    rep(i,0,n) cin>>k[i];
    rep(i,0,n) par[i]=i;
    ll ans[n],vis[n];
    fill(vis,0);
    rep(i,0,n) ans[i]=c[i];
    rep(i,0,n){
        int idx=-1; ll men=inf2;
        rep(j,0,n){
            if(vis[j]==0 && ans[j]<men){
                men=ans[j]; idx=j;
            }
        }
        vis[idx]=1;
        rep(j,0,n){
            if(vis[j]==0 && (ans[j]>(k[idx]+k[j])*(abs(arr[idx].ff-arr[j].ff)+abs(arr[idx].ss-arr[j].ss)))){
                ans[j]=(k[idx]+k[j])*(abs(arr[idx].ff-arr[j].ff)+abs(arr[idx].ss-arr[j].ss));
                par[j]=idx;
            }
        }
    }
    vec a1; vector< pii > a2;
    ll res=0;
    rep(i,0,n){
        res+=ans[i];
        if(par[i]==i) a1.pb(i+1);
        else a2.pb({i+1,par[i]+1});
    }
    cout<<res<<endl;
    cout<<sz(a1)<<endl;
    rep(i,0,sz(a1)) cout<<a1[i]<<" "; cout<<endl;
    cout<<sz(a2)<<endl;
    rep(i,0,sz(a2)) cout<<a2[i].ff<<" "<<a2[i].ss<<endl;
}
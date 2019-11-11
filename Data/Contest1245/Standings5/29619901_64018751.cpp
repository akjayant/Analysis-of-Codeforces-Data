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
    string s; cin>>s;
    int n=sz(s);
    ll dp[mex]={0};
    dp[1]=1; dp[2]=2;
    rep(i,3,mex) dp[i]=(dp[i-1]+dp[i-2])%mod;
    rep(i,0,n){
        if(s[i]=='w' || s[i]=='m'){
            cout<<0<<endl; return 0;
        }
    }
    dp[0]=1;
    ll ans=1; int i=0;
    while(i<n){
        int cnt=0;
        while(i<n && s[i]=='u'){
            cnt++; i++;
        }
        ans=(ans*dp[cnt])%mod;
        cnt=0;
        while(i<n && s[i]=='n'){
            cnt++; i++;
        }
        ans=(ans*dp[cnt])%mod;
        if(i<n && (s[i]!='n' && s[i]!='u')) i++;
    }
    cout<<ans<<endl;
}
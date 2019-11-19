#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll int,ll int>
#define pb push_back
#define ist insert
#define sbit __builtin_popcount
#define vec vector <int>
#define vecs vector <string>
#define vecl vector <ll int>
#define vecp vector <pair<int,int>>
#define vecpl vector <pair<ll int,ll int>>
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define bg begin()
#define en end()
#define el endl
#define all(v) v.bg,v.en
#define ff first
#define ss second
#define wl while
#define sz size()
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define sp(x) setprecision(x)
#define fill(a,b) memset(a,b,sizeof(a))
#define fr(i,n) for(int i=0;i<n;i++)
#define rp(i,a,b) for(int i=a;i<b;i++)
#define rr(i,a,b) for(int i=a;i>=b;i--)
#define ft(it,x) for(auto it : x)
#define dbg(x) cerr<<#x<<" "<<x<<endl;
#define dbga(arr,n) cerr<<#arr<<": "; rep(tt,0,n)cerr<<arr[tt]<<" "; cerr<<endl;
#define mapi map<int,int>
#define mapl map<ll int,ll int>
#define mapc map<char,ll int>
#define maps map<string,ll int>
#define mapss map<string,string>
#define scni(x) scanf("%d",&x)
#define scni(x,y) scanf("%d %d",&x,&y)
#define scnl(x) scanf("%lld",&x)
#define scnl(x,y) scanf("%lld %lld",&x,&y)
#define scns(x) scanf("%s",x)
#define pri(x) printf("%d\n",x)
#define prl(x) printf("%lld\n",x)
#define prs(x) printf("%s\n",x)
#define test(t) int t;cin>>t;while(t--)
#define tests(t) int t;scni(t);while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
const int mod=1e9+7;
const int mex=1e5+5;
inline ll power(ll a,ll b)
{
    ll ans=1,temp=a;
    while(b!=0)
    {
        if(b&1)
        ans=ans*temp;
        ans=ans%mod;
        temp=temp*temp;
        temp=temp%mod;
        b/=2;
    }
    return ans;
}
int pr[mex];
vec prime;
inline void seive()
{
    rp(i,2,mex) pr[i]=1;
    for(int i=2;i*i<mex;i++)
    {
        if(pr[i])
        for(int j=i*i;j<mex;j+=i)
        pr[j]=0;
    }
    rp(i,2,mex)
    {
        if(pr[i]) prime.pb(i);
    }
}
ll int xx,xy,d1;
void exeu(ll int a1,ll int b1)
{
    if(b1==0)
    {
        xx=1;
        xy=0;
        d1=a1;
    }
    else
    {
        exeu(b1,a1%b1);
        ll int temp=xx;
        xx=xy;
        xy=temp-(a1/b1)*xy;
    }
}
ll int modinv(ll int A,ll int M)
{
    exeu(A,M);
    return (xx%M+M)%M;
}
int main()
{
    fast
    test(t)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int ans1=a/c,ans2=b/d;
        if(a%c!=0) ans1++;
        if(b%d!=0) ans2++;
        if((ans1+ans2)<=k) cout<<ans1<<" "<<ans2<<el;
        else cout<<"-1\n";
    }
    return 0;
}
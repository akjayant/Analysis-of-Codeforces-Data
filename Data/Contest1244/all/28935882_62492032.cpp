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
#define rp(i,a,b) for(ll int i=a;i<b;i++)
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
bool vis[6][100005];
vec v[100005],v1;
ll int dp[6];
ll int ct[3][100005];
mapi mp;
int x=0;
void dfs(int s,int k)
{
    vis[k][s]=true;
    if(k==0)
    v1.pb(s);
    dp[k]+=ct[mp[x]][s];
    x=(x+1)%3;
    
    fr(i,v[s].size())
    {
        if(!vis[k][v[s][i]])
        {
            dfs(v[s][i],k);
        }
    }
}
int main()
{
    fast
    int n;
    cin>>n;
    fr(i,3) fr(j,n) cin>>ct[i][j];
    fr(i,n-1)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    int s=-1,fg=1;
    fr(i,n)
    {
        if(v[i].sz>2)
        {
            fg=0;
            break;
        }
    }
    fr(i,n)
    {
        if(v[i].sz==1)
        {
            s=i;
            break;
        }
    }
    if(fg==0 || s==-1) 
    {
        cout<<"-1\n";
        return 0;
    }
    fr(i,6)
    {
        if(i==0)
        {
            mp[0]=0;
            mp[1]=1;
            mp[2]=2;
        }
        else if(i==1)
        {
            mp[0]=0;
            mp[1]=2;
            mp[2]=1;
        }
        else if(i==2)
        {
            mp[0]=1;
            mp[1]=0;
            mp[2]=2;
        }
        else if(i==3)
        {
            mp[0]=1;
            mp[1]=2;
            mp[2]=0;
        }
        else if(i==4)
        {
            mp[0]=2;
            mp[1]=0;
            mp[2]=1;
        }
        else if(i==5)
        {
            mp[0]=2;
            mp[1]=1;
            mp[2]=0;
        }
        dfs(s,i);
        x=0;
    }
    ll int ans=LLONG_MAX,id=-1;
    fr(i,6)
    {
        //cout<<i<<" "<<dp[i]<<el;
        if(ans>dp[i])
        {
            ans=dp[i];
            id=i;
        }
    }
    cout<<ans<<el;
    int col[n]={0};
    x=0;
    ft(it,v1)
    {
       // cout<<it<<el;
        if(id==0)
        {
            mp[0]=0;
            mp[1]=1;
            mp[2]=2;
        }
        else if(id==1)
        {
            mp[0]=0;
            mp[1]=2;
            mp[2]=1;
        }
        else if(id==2)
        {
            mp[0]=1;
            mp[1]=0;
            mp[2]=2;
        }
        else if(id==3)
        {
            mp[0]=1;
            mp[1]=2;
            mp[2]=0;
        }
        else if(id==4)
        {
            mp[0]=2;
            mp[1]=0;
            mp[2]=1;
        }
        else if(id==5)
        {
            mp[0]=2;
            mp[1]=1;
            mp[2]=0;
        }
        col[it]=mp[x];
        x=(x+1)%3;
    }
    fr(i,n) cout<<col[i]+1<<" ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

ll power(ll x,ll y,ll p){ll r=1; x=x%p; while(y){ if(y&1) r= r*x%p; y=y>>1; x=x*x%p; } return r; }
/*  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int csrand(int l=0, int r=1e9)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define PR(x) cout<<#x<<" : "<<x<<"\n";
#define PR1(x,y) cout<<#x<<" : "<<x<<"  |  "<<#y<<" : "<<y<<"\n";
#define PR2(x,y,z) cout<<#x<<" : "<<x<<"  |  "<<#y<<" : "<<y<<"  |  "<<#z<<" : "<<z<<"\n";
#define ED cout<<'\n';

#define IO              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FILEIO          freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define all(v)          v.begin(),v.end()
#define endl            '\n'
#define fr1(j,n)        for(int j=0;j<n;j++)
#define fr(n)           for(int i=0;i<n;i++)
#define PB              push_back
#define pii             pair<int,int>
#define pll             pair<long long int,long long int>
#define F               first       
#define S               second 
#define mod             1000000007




const int N=2e5+99;
ll n;
ll dp[N];
string s;

ll solve(int i)
{
    if(i==n)
        return 1;
    if(dp[i]!=-1)
        return dp[i];
    ll ans=0;
    if(i!=n-1 && s[i]=='u' && s[i+1]=='u')
        ans=solve(i+1)+solve(i+2);

    else if(i!=n-1 && s[i]=='n' && s[i+1]=='n')
        ans=solve(i+1)+solve(i+2);
    else
        ans=solve(i+1);
    ans%=mod;
    return dp[i]=ans;
}

int32_t main()
{       
    IO
    #ifndef ONLINE_JUDGE      
    FILEIO
    #endif  

    fr(N) dp[i]=-1;
    cin>>s;
    n=s.length();
    for(auto x:s)
    {
        if(x=='m' || x=='w')
        {
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<solve(0)<<endl;



}

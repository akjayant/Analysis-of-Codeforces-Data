
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))
#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
#define int  long long int
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll hell =1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int dp1[100001][2];int dp[100001][2];
int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    //int dp[n+1][2];
    dp[0][0]=1;dp[0][1]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][0]=(dp[i][0]%hell+dp[i-2][0]%hell)%hell;
        dp[i][1]=dp[i-1][0];
        dp[i][1]=(dp[i][1]%hell+dp[i-2][1]%hell)%hell;
        //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    
    int ans=(dp[n][1]%hell+dp[n][0]%hell)%hell;
    ans=(ans-2+hell)%hell;
   // cout<<ans<<endl;
    dp1[0][0]=1;
    dp1[0][1]=1;
    dp1[1][0]=1;
    dp1[1][1]=1;
    for(int i=2;i<=m;i++)
    {
        //dp1[i][0];
        dp1[i][0]=(dp1[i-1][1])%hell;
        dp1[i][0]=(dp1[i][0]%hell+dp1[i-2][1]%hell)%hell;
        dp1[i][1]=(dp1[i-1][0])%hell;
        dp1[i][1]=(dp1[i][1]%hell+dp1[i-2][0]%hell)%hell;
        //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    ans=(ans%hell+dp1[m][0]%hell)%hell;
    ans=(ans%hell+dp1[m][1]%hell)%hell;
    cout<<(ans)%hell<<endl;
    return 0;
}

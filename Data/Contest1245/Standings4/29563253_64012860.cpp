#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define  int long long int
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector<vector<int> > matrix;
#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))
#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
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
 int dp[200001];
int32_t main()
{
    //IOS;
    string s;
    cin>>s;
    //cout<<s<<endl;
    int n=s.length();
    //cout<<1<<endl;
    //debug(1);
   
    dp[0]=1;
    dp[1]=1;vector<int> v;int k=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=(dp[i-1]%hell+dp[i-2]%hell)%hell;
    }
    //cout<<1<<endl;
    for(int i=0;i<n;i++)
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0<<endl;
            return 0;
        }
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1]&&s[i]=='u')
        {
            k++;
        }
        else
        {
            v.pb(k+1);
            k=0;
        }
    }
    if(s[n-1]=='u')
        v.pb(k+1);
    k=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1]&&s[i]=='n')
        {
            k++;
        }
        else
        {
            v.pb(k+1);
            k=0;
        }
    }
    if(s[n-1]=='n')
        v.pb(k+1);
    int ans=1;
    for(int i=0;i<v.size();i++)
    {
        //cout<<v[i]<<endl;
        ans=(ans*dp[v[i]])%hell;
    }
    cout<<ans<<endl;
    return 0;
}

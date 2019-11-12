#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef pair<ll,ll> pli;
typedef pair<int,int> pii;
typedef pair<ld,ld> pld;

ll MOD=1000000007;
ll base=29;
ll MX=1e9;
ld pi=3.1415926535;
ll INF=400000000;


ll power(ll a,ll n,ll mod)
{
    if(n==0) return 1;
    if(n%2==0)
    {
       ll ans=power(a,n/2,mod);
       ans%=mod;
       ans*=ans;
       ans%=mod;
       return ans;
    }
    else
    {
       ll ans=power(a,n/2,mod);
       ans%=mod;
       ans*=ans;
       ans%=mod;
       ans*=a;
       ans%=mod;
       return ans;
    }
}


int main()
{
    fast;
    //freopen("input.txt","r",stdin);
    ll n,m;
    cin>>n>>m;
    ll temp=(power(2,m,MOD)-1+MOD)%MOD;
    cout<<power(temp,n,MOD);
    return 0;
}

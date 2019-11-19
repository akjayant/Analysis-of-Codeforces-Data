#include <bits/stdc++.h>    
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb  push_back
#define show(x) cout<<(#x)<<" : "<<x<<endl;
#define ll  long long
#define ld  long double
#define fill(a,val) memset(a,val,sizeof(a))
#define mp  make_pair
#define ff  first
#define ss  second
#define pii pair<ll,ll>
#define sq(x) ((x)*(x))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 1ll*1000*1000*1000 + 7;
const ll N       = 1ll*1000*1000*1000*1000*1000;
const ll N2      = 1000*100;
const ld PI  = 3.14159265;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p = INF){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
std::vector<ll> v;
void printDivisors(ll n) 
{ 
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i) // check if divisors are equal 
                v.pb(i);
            else
            { 
                v.pb(i);
  
                // push the second divisor in the vector 
                v.push_back(n/i); 
            } 
        } 
    } 
} 
signed main()
{
    //CHECK for LONG LONG and LONG DOUBLE
    //comment for all except cc/cf    
    #ifndef ONLINE_JUDGE
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
    #endif//*/ 
    fastio();
   	ll n;
   	cin>>n;
   	if(n==1)
   	{
   		cout<<1;
   		return 0;
   	}

   	printDivisors(n);
   	ll ans = v[1];
   	for (int i = 1; i < v.size(); ++i)
   	{
   		ans = gcd(ans,v[i]);
   	}
   	cout<<ans;
    return 0;
}
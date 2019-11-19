#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define f(i,x,n) for(ll i=x;i<n;i++)
#define fl(i,x,n) for(ll i=n;i>=x;i--)
#define MOD (ll)1e9+7
#define print(x) cout<<x<<endl
#define vec vector<ll>
#define pai pair<ll, ll>
#define itr(it) :: iterator it
#define MAX (ll)1e16
#define MIN (ll)-1e16
#define X first
#define Y second
#define up upper_bound
#define lo lower_bound
using namespace std;
       ///////////   ///     ///   ///      ///   ////////////  ///      ///
       ///           ///     ///   ///      ///   ///      ///  ///      ///
       ///           ///     ///   ///      ///   ///      ///  ///      ///
       ///////////   ///////////   ///      ///   ////////////  ////////////
               ///   ///     ///   ///      ///   ///      ///  ///      ///
               ///   ///     ///   ///      ///   ///      ///  ///      ///
       ///////////   ///     ///   ////////////   ////////////  ///      ///
ll minn( ll a , ll b) 
{
    if(a>b)
        return b;
    return a;
}
ll maxx2( ll a , ll b)
{
    if(a>b)
        return a;
    return b;
}
ll maxx(ll a,ll b,ll c)
{
  return maxx2(a,maxx2(b,c));
}
ll gcdd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcdd(b,a%b);
}
ll dsum(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
ll poww(ll a,ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    else
        return ((poww(a,b/2)%998244353)*(poww(a,b/2)%998244353)*(poww(a,b%2)%998244353))%998244353;
}
long double gcdf(long double a, long double b) 
{ 
    if (a < b) 
        return gcdf(b, a); 
    if (fabs(b) < 0.000001) 
        return a; 
    else
        return (gcdf(b, a - floor(a / b) * b)); 
} 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll x=-1,y=-1;
        f(i,0,n)
        {
            if(s[i]=='1')
            {
                x=i;
                break;
            }
        }
        for(ll i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                y=i;
                break;
            }
        }
        if(x==-1)
        {
            cout<<n<<endl;
        }
        else
        {
            ll ans = maxx2(n-x,y+1);
            cout<<ans*2<<endl;
        }
    }
    return 0;
}
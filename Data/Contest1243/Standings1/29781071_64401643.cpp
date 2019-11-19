#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define MX LLONG_MAX
#define MN LLONG_MIN

const ll mod=1e9+7;
const ll N=1e6+5;

ll powermodm(ll x,ll n,ll M){ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
ll power(ll _a,ll _b){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}          
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}

int32_t main()                  
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            v.pb(n/i);
        }
    }
    ll ans = n;
    for(ll i=0;i<v.size();i++)
    {
        ans = gcd(ans,v[i]);
    }
    cout<<ans;
    return 0;
}

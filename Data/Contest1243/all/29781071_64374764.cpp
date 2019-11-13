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
const ll N=1e3+5;

ll powermodm(ll x,ll n,ll M){ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
ll power(ll _a,ll _b){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}          
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}

int32_t main()                  
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],arr[1005]={0},c=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            arr[a[i]]++;
            c++;
        }
        ll ans = 0;
        for(ll i=1;i<1005;i++)
        {
            if(c >= i)
                ans = i;
            c -= arr[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define ll long long int
#define ull unsigned long long int
#define db long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define deb1(n) cout<<n<<"\n"
#define deb2(a,b) cout<<a<<" "<<b<<"\n"
#define deba(a,n) for(i=0;i<n;++i) {  cout<<a[i]<<" "; };cout<<"\n"
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define MOD 1000000007
#define inf LLONG_MAX
#define PI 3.141592653589793238463

ll binary_exp(ll a,ll n)
{
    ll i=1;
    while(n>0)
    {
        if(n%2==1)
            i=(i*a)%MOD;
        a=(a*a)%MOD;
        n/=2;
    }
    return i;
}

ll IsPrime(ll n)
{
    if(n==0||n==1)
        return n;
    if(n%2==0)
        return (ll)2;
    if(n%3==0)
        return (ll)3;
    else
    {
        for(ll i=5;i*i<=n;i+=6)
        {
            if(n%i==0)
                return i;
            if(n%(i+2)==0)
                return (i+2);
        }
        return n;
    }
}

int main()
{
    fast;
    ll n,m,temp,ans;
    cin>>n>>m;
    temp=(binary_exp(2LL,m)-1+MOD)%MOD;
    ans=binary_exp(temp,n);
    cout<<ans;
}


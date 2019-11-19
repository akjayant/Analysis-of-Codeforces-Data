/*
सत्यान्न प्रमदितव्यम्  || 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define mx 1000005
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define fast_as_levi ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define mxi 2005

vector<ll> ar;
    
ll sieve(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(!(n%i))
        {
            ar.pb(i);
        }
        if(!(n%i) && (i*i <n))
        ar.pb(n/i);
    }
    ar.pb(n);
    return ar.size();
}

int main()
{
    fast_as_levi;
    ll i,n;
    cin>>n;
    ll ans = 0;
    ll z = sieve(n);
    for(i=0;i<z;i++)
    {
        ans = __gcd(ans,ar[i]);
    }
    cout<<ans<<"\n";
}
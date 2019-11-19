#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
    ll n;
    scanf("%lld", &n);

    ll ans= n;
    ll tmp= n;

    for( ll i=2;i*i<=n;i++ )
    {
        if( n%i==0 )
        {
            ans= __gcd(ans,i);

            while( n%i==0 )
                n/= i;
        }
    }

    if( n>1 and n<tmp )
        ans= __gcd(ans,n);

    printf("%lld\n", ans);
}

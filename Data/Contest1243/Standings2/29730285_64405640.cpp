#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int main()
{
    ll n;
    cin>>n;
    ll nas=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            nas=__gcd(nas,(ll)i);
            nas=__gcd(nas,n/i);
        }
    }
    if(nas==0)
        printf("%lld",n);
    else
        printf("%lld",nas);
    return 0;

}
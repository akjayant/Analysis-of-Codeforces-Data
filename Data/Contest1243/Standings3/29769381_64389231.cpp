#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    while(scanf("%lld", &n)==1)
    {
        ll res= n;
        for(ll i=2; i*i<=n; i++)
            if(!(n%i))
            {
                res= __gcd(res, i);
                while(!(n%i))
                    n/= i;
            }
        if(n!=1)res= __gcd(res, n);
        printf("%lld\n", res);
    }return 0;
}

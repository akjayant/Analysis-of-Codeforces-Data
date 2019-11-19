#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        ll su1=0;
        ll su2=0;
        ll su3=0;
        ll su4=0;
        scanf("%lld",&n);
        for(ll i=0;i<n;i++)
        {
            ll nu;
            scanf("%lld",&nu);
            if(nu%2)
            {
                su1++;
            }
            else
            {
                su2++;
            }
        }
        ll m;
        ll ans=0;
        scanf("%lld",&m);
        for(int i=0;i<m;i++)
        {
            ll nu;
            scanf("%lld",&nu);
            if(nu%2)
            {
                ans+=su1;
            }
            else
            {
                ans+=su2;
            }
        }
        printf("%lld\n",ans);
    }
}

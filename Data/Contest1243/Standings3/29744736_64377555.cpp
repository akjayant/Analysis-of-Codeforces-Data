#include <bits/stdc++.h>
#define pb push_back
#define sc1(x) scanf("%lld",&x)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
#define sc3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define MX 100000
#define PI acos(-1)
#define block 320
using namespace std;

typedef long long int ll;
ll arr[100005];
int main()
{
    ll test;
    sc1(test);
    while(test--)
    {
        ll n;
        sc1(n);
        for(ll i=0;i<n;i++)
        {
            sc1(arr[i]);
        }
        sort(arr,arr+n);
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            if(i+arr[i]<=n)
            {
                ans=max(ans,arr[i]);
            }
            ll mn=min(n-i,arr[i]);
            ans=max(ans,mn);
        }
        cout<<ans<<endl;
    }
    return 0;
}

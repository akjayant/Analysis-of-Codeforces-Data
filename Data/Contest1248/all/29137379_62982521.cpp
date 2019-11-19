#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e5+10;
const ll mod = 998244353;
const ll inf = 1e18;

ll a[MAXN],b[MAXN];
ll n,m;
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll s0=0,s1=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]&1)
                s0++;
            else
                s1++;
        }
        ll s2=0,s3=0;
        scanf("%lld",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]&1)
                s2++;
            else
                s3++;
        }
        printf("%lld\n",s0*s2+s1*s3);
    }
}

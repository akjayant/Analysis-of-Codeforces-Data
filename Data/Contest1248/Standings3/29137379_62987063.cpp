#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e5+10;
const ll mod = 998244353;
const ll inf = 1e18;

ll a[MAXN];
ll n,s0,s1;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(i<=n/2)
            s0+=a[i];
        else
            s1+=a[i];
    }
    printf("%lld\n",s0*s0+s1*s1);
}

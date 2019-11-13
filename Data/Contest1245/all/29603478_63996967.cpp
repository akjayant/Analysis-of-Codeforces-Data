#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10,mod=998244353;
ll a[N];
int main()
{
    //freopen("i.txt","r",stdin);
    ll n;
    scanf("%lld",&n);
    while(n--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        if(__gcd(a,b)==1)puts("Finite");
            else puts("Infinite");
    }

    //for(int i=0;i<n;i++)scanf("%lld",&a[i]);

}

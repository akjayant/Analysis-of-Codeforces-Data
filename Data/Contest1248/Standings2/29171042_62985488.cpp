#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100100];
int main()
{
    ll n,sum1=0,sum2=0,sum=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    stable_sort(a+1,a+1+n);
    for(int i=1; i<=n/2; i++)
    {
        sum1=sum1+a[i];
    }
    printf("%lld\n",1ll*sum1*sum1+1ll*(sum-sum1)*(sum-sum1));
    return 0;
}

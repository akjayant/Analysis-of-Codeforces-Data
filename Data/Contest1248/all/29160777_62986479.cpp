#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MA=1e5+5;

ll a[MA];

int main()
{
    int n;
    ll all=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
        all+=a[i];
    }
    sort(a,a+n);
    ll sum=0;
    for(int i=0;i<n/2;++i)sum+=a[i];
    printf("%lld\n",sum*sum+(all-sum)*(all-sum));
    return 0;
}

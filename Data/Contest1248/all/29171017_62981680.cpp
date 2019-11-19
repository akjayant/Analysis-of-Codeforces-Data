#include<bits/stdc++.h>
using namespace std;
typedef long long L;

L a[100100];
int main()
{
    L n,d1=0,d2=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n/2;i++){
        d1=d1+a[i];
    }
    for(int i=n/2+1;i<=n;i++){
        d2=d2+a[i];
    }
    printf("%lld\n",1ll*d1*d1+1ll*d2*d2);
    return 0;
}

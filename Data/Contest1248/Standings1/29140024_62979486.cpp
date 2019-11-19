#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int main()
{
     int n;
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
     }
     sort(a+1,a+n+1);
     ll s1=0;
     for(int i=1;i<=n/2;i++){
        s1+=a[i];
     }
     ll s2=0;
     for(int i=n/2+1;i<=n;i++){
        s2+=a[i];
     }
     printf("%lld\n",s2*s2+s1*s1);
}
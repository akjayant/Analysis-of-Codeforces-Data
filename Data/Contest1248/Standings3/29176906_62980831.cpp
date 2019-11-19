#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,tot,a[100010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)tot+=a[i];
    printf("%lld",tot*tot+(sum-tot)*(sum-tot));
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+5;
int a[maxn];
#define LL long long
LL sum1=0,sum2=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)sum1+=a[i];
    for(int i=n/2+1;i<=n;i++)sum2+=a[i];
    printf("%lld\n",sum1*sum1+sum2*sum2);
}

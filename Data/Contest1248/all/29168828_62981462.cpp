#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200000],sum1,sum2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)
	sum1=sum1+a[i];
    for(int i=n/2+1;i<=n;i++)
	sum2=sum2+a[i];
    //printf("%lld %lld\n",sum1,sum2);
    printf("%lld\n",sum1*sum1+sum2*sum2);
}

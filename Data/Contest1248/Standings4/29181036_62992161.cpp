#include<stdio.h>
#include<algorithm>
using namespace std;

long long a[100005];

int main()
{
	int n,m,i;
	long long sum1=0,sum2=0,tot=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),tot+=a[i];
	sort(a,a+n+1);
	m=n/2;
	for(i=1;i<=m;i++)sum1+=a[i];
	for(i=n;i>n-m;i--)sum2+=a[i];
	sum1=sum1*sum1+(tot-sum1)*(tot-sum1);
	sum2=sum2*sum2+(tot-sum2)*(tot-sum2);
	printf("%lld",max(sum1,sum2));
}
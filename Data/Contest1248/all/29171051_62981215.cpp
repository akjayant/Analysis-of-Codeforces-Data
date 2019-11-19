#include<stdio.h>
#include<algorithm>
using namespace std;
int t;
long long a[1000005];
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	scanf("%I64d",&a[i]);
	sort(a+1,a+t+1);
	long long ax=0,bx=0;
	for(int i=t/2+1;i<=t;i++)ax+=a[i];
	for(int i=t/2;i;i--)bx+=a[i];
	printf("%I64d",ax*ax+bx*bx);
	return 0;
}
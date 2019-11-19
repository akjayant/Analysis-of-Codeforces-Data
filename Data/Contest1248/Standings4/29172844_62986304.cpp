#include<cstdio>
#include<algorithm>
using std::sort;
int a[100100],n;
long long x,y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++)
	{
		x+=a[i];
	}
	for(int i=n/2+1;i<=n;i++)
	{
		y+=a[i];
	}
	printf("%I64d\n",x*x+y*y);
	return 0;
}

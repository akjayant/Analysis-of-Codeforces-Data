#include<cstdio>
#include<algorithm>
const int MaxN=100000;
int n;
long long a[MaxN+1],X=0,Y=0;
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(i=1,j=n;i<=j;++i,--j)
	{
		if(i==j)
			Y+=a[i];
		else
			X+=a[i],Y+=a[j];
	}
	printf("%lld\n",X*X+Y*Y);
	return 0;
}
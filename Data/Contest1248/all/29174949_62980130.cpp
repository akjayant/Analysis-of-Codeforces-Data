#include <cstdio>

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n,m; scanf("%d",&n);
		long long a=0,b=0,c=0,d=0;
		for(int i=1; i<=n; i++)
		{
			int x; scanf("%d",&x);
			if(x%2==0) a++;
			else b++;
		}
		scanf("%d",&m);
		for(int i=1; i<=m; i++)
		{
			int x; scanf("%d",&x);
			if(x%2==0) c++;
			else d++;
		}
		long long sum=a*c+b*d;
		printf("%lld\n",sum);
	}
	return 0;
}

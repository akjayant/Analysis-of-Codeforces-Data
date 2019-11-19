#include <cstdio>
#define p 1000000007

long long pi[233333];

int main()
{
	pi[1]=1; pi[2]=2;
	for(int i=3; i<=100000; i++) pi[i]=(pi[i-1]+pi[i-2])%p;
	int n,m; scanf("%d%d",&n,&m);
	printf("%lld",(pi[n]+pi[m]-1)*2%p);
	return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

int pi[233333];

int main()
{
	int n; scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&pi[i]);
	sort(pi+1,pi+1+n);
	long long a=0,b=0;
	for(int i=n/2+1; i<=n; i++) a+=pi[i];
	for(int i=1; i<=n/2; i++) b+=pi[i];
	printf("%lld",a*a+b*b);
	return 0;
}

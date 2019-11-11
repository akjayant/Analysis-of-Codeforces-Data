#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=10086;
int a,b,n;
int T;
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		n=gcd(max(a,b),min(a,b));
		if(n==1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}
	return 0;
}

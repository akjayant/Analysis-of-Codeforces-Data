#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int t,a,b;

int gcd(int x,int y)
{
	return !y ? x : gcd(y,x % y);
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&a,&b);
		if (gcd(a,b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}

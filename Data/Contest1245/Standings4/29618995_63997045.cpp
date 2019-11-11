#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int T,a,b;
int gcd(int x,int y)
{
	if (!y)
		return x;
	return gcd(y,x % y);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		if (gcd(a,b) == 1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}
	return 0;
}
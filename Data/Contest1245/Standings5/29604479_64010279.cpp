#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(__gcd(a, b) == 1)
			puts("Finite");
		else
			puts("Infinite");
	}
	return 0;
}
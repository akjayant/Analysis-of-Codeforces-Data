#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d", &q);
	while (q--) { 
		int a, b;
		scanf("%d%d", &a, &b);
		if (__gcd(a,b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}
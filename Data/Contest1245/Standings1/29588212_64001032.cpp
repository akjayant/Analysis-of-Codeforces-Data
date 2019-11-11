#include<bits/stdc++.h>

using namespace std;

main()
{
	int a, b, N;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d %d", &a, &b);
		printf("%s\n", __gcd(a, b) == 1 ? "Finite" : "Infinite");
	}
	return 0;
}

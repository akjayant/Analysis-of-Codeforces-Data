#include<bits/stdc++.h>
using namespace std;

main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(__gcd(a,b)==1)printf("Finite\n");
		else printf("Infinite\n");
	}
}
#include <bits/stdc++.h>
using namespace std;
int G,n,m;
int gcd(int A,int B) { return B?gcd(B,A%B):A; }
int main()
{
	scanf("%d",&G);
	while (G--)
	{
		scanf("%d%d",&n,&m);
		if (gcd(n,m)==1) printf("Finite\n"); else printf("Infinite\n");
	}
	return 0;
}

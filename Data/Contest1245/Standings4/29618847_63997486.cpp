#include<bits/stdc++.h>
using namespace std;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

using ll = long long;

int n,m,t;
int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		if(__gcd(n,m)==1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}
}


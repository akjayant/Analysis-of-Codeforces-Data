#include<cstdio>
#include<cmath>
 #include<bits/stdc++.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;
int n;
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&a,&b);
		int g=__gcd(a,b);
		if (g==1)
		{
			puts("Finite");
			continue;
		}
		puts("InFinite");
	}
}


#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int aa,bb;
		if(a%c==0)
		{
			aa=a/c;
		}
		else
		{
			aa=a/c+1;
		}
		if(b%d==0)
		{
			bb=b/d;
		}
		else
		{
			bb=b/d+1;
		}
		if(aa+bb>k)
		{
			printf("-1\n");
			continue;
		}
		printf("%d %d\n",aa,bb);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,k;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if (ceil((double)a/c)+ceil((double)b/d)>k) printf("-1\n");
		else
		{
			int now=ceil((double)a/c);
			printf("%d %d\n",now,k-now);
		}
//		else printf("%d %d\n",ceil((double)a/c),k-ceil((double)a/c));
	}
	return 0;
} 

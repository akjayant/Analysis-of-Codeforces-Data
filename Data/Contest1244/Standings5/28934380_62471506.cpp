#include <bits/stdc++.h>
int t,a,b,c,d,k;
int main()
{
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
	    int ans1=0;
		int ans2=0;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		if(a%c==0)
			ans1=a/c;
		else
			ans1=a/c+1;
		if(b%d==0)
			ans2=b/d;
		else
			ans2=b/d+1;
		if(ans1+ans2<=k)
			printf("%d %d",ans1,ans2);
		else
			printf("-1");
		
		printf("\n");
	}
	return 0;
	
}
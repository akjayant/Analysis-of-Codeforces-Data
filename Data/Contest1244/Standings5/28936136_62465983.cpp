#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,x,y,k;
		scanf("%d%d%d%d%d",&a,&b,&x,&y,&k);
		int p=a/x+(a%x>0);
		int c=b/y+(b%y>0);
		if(p+c<=k)
			printf("%d %d\n",p,c);
		else puts("-1");
	}
	return 0;
}
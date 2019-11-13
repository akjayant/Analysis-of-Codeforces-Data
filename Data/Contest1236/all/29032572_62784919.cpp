#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d%d%d",&a,&b,&c);
		while(b>=1&&c>=2)
			ans+=3,--b,--c,--c;
		while(b>=2&&a>=1)
			ans+=3,--b,--b,--a;
		printf("%d\n",ans);
	}
	return 0;
}
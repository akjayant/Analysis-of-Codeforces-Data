#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int ans1=a/c+(a%c!=0);
		int ans2=b/d+(b%d!=0);
		if(ans1+ans2<=k)
			printf("%d %d\n",ans1,ans2);
		else
			printf("-1\n");
	}
	return 0;
}
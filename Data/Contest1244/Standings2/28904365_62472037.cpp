#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int main()
{
	scanf("%d",&T);
while(T--)
{
	scanf("%d",&n);
	int ans=n;
	int b;
	for(int i=1;i<=n;++i)
	{
		scanf("%1d",&b);
		if(!b)continue;
		ans=max(ans,max(i,n-i+1)*2);
	}
	printf("%d\n",ans);
}
	return 0;
}

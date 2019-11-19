#include<iostream>
#include<cstdio>
using namespace std;
int T,n,a[101010],q[101010],ans; 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int b=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%1d",&a[i]);
			if(a[i]) q[++b]=i;
		}
		if(b)
		{
			ans=max(ans,2*(q[b]-q[1]+1));
			ans=max(ans,max(2*q[b],(n-q[1]+1)*2));
		}
		else ans=n;
		printf("%d\n",ans);
	}
	return 0;
}

#include<cstdio>
int t,a,b,c;
int main()
{
	int ans=0;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d",&a,&b,&c);
		while(b&&c>=2)
			--b,c-=2,ans+=3;
		while(a&&b>=2)
			--a,b-=2,ans+=3;
		printf("%d\n",ans);
	}
	return 0;
}
#include<cstdio>

inline int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		ans=min(c/2,b);
		c-=2*ans;b-=ans;ans*=3;
		ans=ans+min(b/2,a)*3;
		printf("%d\n",ans);
	}
}

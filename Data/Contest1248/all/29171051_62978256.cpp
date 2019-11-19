#include<stdio.h>
int main()
{
	int t,n,p,q,e,o,e_,o_;
	scanf("%d",&t);
	while(t--)
	{
		e=0;o=0;
		e_=0;o_=0;
		int temp;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			if(temp<0)temp=-temp;
			if(temp%2)e++;else o++;
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			if(temp<0)temp=-temp;
			if(temp%2)e_++;else o_++;
		}
		printf("%I64d\n",(long long)e_*(long long)e+(long long)o_*(long long)o);
	}
	return 0;
}
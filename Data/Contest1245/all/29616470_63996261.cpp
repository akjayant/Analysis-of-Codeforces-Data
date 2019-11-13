#include <cstdio>
#include <cstring>
int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
int t,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(gcd(a,b)!=1)printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}
#include<cstdio>
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int T,a,b;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		puts(gcd(a,b)==1?"Finite":"Infinite");
	}
	return 0;
}

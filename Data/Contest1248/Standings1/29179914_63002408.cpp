#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

const int NMAX = 1123456;
char in [NMAX];
int n;

int main()
{
	scanf("%d %s",&n,in);
	int sum = 0;
	int minsum=0;
	int rotace=0;
	for(int i=0;i<n;i++)
	{
		in[i+n]=in[i];
		if(sum<minsum)
		{
			minsum=sum;
			rotace=i;
		}
		if(in[i]=='(') sum++;
		else sum--;
	}
	if(sum)
	{
		D printf("NEIDE %s %d\n",in,sum);
		printf("0\n1 1\n");
		exit(0);
	}
	int ifnoch=0;
	int outa=0;
	int outb=0;
	int outc=0;
	char * s=in+rotace;
	sum=0;
	for(int i=0;i<n;i++)
	{
		if(sum==0) ifnoch++;
		if(s[i]=='(') sum++;
		else sum--;
	}
	outa=ifnoch;
	int z1b,z2b, z1in, z2in;
	sum=0;
	D printf("r:%d %s\n",rotace,s);
	for(int i=0;i<n;i++)
	{
		if(s[i]==')' && sum==1)
		{
			if(outa<z1in+1)
			{
				outa=z1in+1;
				outb=z1b;
				outc=i;
			}
		}
		if(s[i]==')' && sum==2)
		{
			if(outa<ifnoch+z2in+1)
			{
				outa=ifnoch+z2in+1;
				outb=z2b;
				outc=i;
			}
		}
		if(s[i]=='(') sum++;
		else sum--;
		if(s[i]=='(' && sum==1)
		{
			z1b=i;
			z1in=0;
		}
		if(s[i]=='(' && sum==2)
		{
			z2b=i;
			z2in=0;
			z1in++;
		}
		if(s[i]=='(' && sum==3)
		{
			z2in++;
		}
	}
	printf("%d\n%d %d\n",outa,(outb+rotace)%n+1,(outc+rotace)%n+1);



	return 0;
}

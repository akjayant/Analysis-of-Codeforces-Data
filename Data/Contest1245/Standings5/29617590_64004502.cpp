#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a,b;
int t;
int gcd(int a,int b)
{
	if(a<b)
	{
		swap(a,b);
	}
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&t);
	for(int o=1;o<=t;o++)
	{
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1)
		{
			printf("Finite\n");
		}
		else
		{
			printf("Infinite\n");
		}
	}
	return 0;
} 
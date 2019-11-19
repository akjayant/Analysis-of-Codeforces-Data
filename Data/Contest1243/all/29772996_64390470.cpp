#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define debug printf("\n-------------\n")
using namespace std;
typedef long long ll;
ll n;
int main()
{
	scanf("%I64d",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(ll i=2;i*i<=n;i++)
	{
		ll tmp=n;
		if(n%i)
			continue;
		while(tmp%i==0)
			tmp/=i;
		if(tmp==1)
		{
			printf("%I64d",i);
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
	printf("%I64d",n);
	return 0;
}
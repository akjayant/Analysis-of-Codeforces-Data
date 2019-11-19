#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef DEB
#define D if(1)
#else
#define D if(0)
#endif

int NMAX = 1123456;

void task()
{
	int n;
	ll a=0,b=0,c=0,d=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp%2) a++;
		else b++;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp%2)c++;
		else d++;
	}
	printf("%lld\n",a*c+b*d);
}
int main()
{
	int t;
	scanf("%d",&t);
for(;t;t--)
task();	
	return 0;
}

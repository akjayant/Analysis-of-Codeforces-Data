#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
vector<int> v;
int prime(ll n)
{
	if(n==1||n==2)
	return 1;
	
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	if(prime(n))
	{
		printf("%lld",n);
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
			}
			v.pb(i);
		}
	}
	if(n>1)
	{
		v.pb(n);
	}
	if(v.size()==1)
	{
		printf("%d",v[0]);
	}
	else
	{
		printf("1\n");
	}
}

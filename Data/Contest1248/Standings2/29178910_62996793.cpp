#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll calc(int n)
{
	if(n==1)
		return 2;
	if(n==2)
		return 4;
	long long a = 2,b = 4;
	for(int i = 1;i<=n-2;i++)
	{
		ll c = a+b;
		a = b;
		b = c;
		a%=mod;
		b%=mod;
	}
	return b;
}


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	ll res = calc(a)+calc(b)-2;
	res%=mod;
	cout<<res;







	return 0;
}

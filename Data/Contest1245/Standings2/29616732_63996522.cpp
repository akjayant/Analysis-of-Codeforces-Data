#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int mo=1e9+7;

LL qpow(LL a,LL b)
{
	LL ans=1;
	a%=mo;
	while(b)
	{
		if(b&1)
			ans=ans*a%mo;
		b>>=1;
		a=a*a%mo;
	}
	return ans;
}


int main()
{
	int T;
	scanf("%d",&T);
	int a,b;
	int gcd;
	while(T--)
	{
		cin>>a>>b;
		gcd= __gcd(a,b);
		if(gcd==1)
			printf("Finite\n");
		else
		
			printf("Infinite\n");
	}
	
	return 0;
}
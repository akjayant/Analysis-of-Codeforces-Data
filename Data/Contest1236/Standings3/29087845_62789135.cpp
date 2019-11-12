#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;

int n,m;

inline long long fpow(long long a,long long b)
{
	a%=M;long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r%M;
}

int main()
{
	scanf("%d %d",&n,&m);
	printf("%lld\n",fpow(fpow(2,m)-1+M,n));
	return 0;
}
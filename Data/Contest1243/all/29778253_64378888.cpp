#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,ans;
int main()
{
	scanf("%lld",&n); ans=n;
	for (long long i=2;i*i<=n;i++)
	if (n%i==0) ans=__gcd(ans,i),ans=__gcd(ans,n/i);
	printf("%lld\n",ans);
return 0;
}
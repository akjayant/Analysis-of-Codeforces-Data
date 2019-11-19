#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define int long long
int n,m;
vector <int> ys;
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
signed main()
{
	scanf("%lld",&n);
	int ok=1;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ok=0;
			ys.push_back(i);
			ys.push_back(n/i);
		}
	}
	if(ok)
	{
		printf("%lld\n",n);
		return 0;
	}
	else
	{
		int k=ys[0];
		int si=ys.size();
		for(int i=1;i<si;i++)
			k=gcd(k,ys[i]);
		printf("%lld\n",k);
	}
	return 0;
}



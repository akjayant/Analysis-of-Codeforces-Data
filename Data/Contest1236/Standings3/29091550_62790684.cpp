#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;

long long mi(long long a,long long b)
{
	if (!b) return 1;
	if (b==1) return a;
	if (b%2)
		return (((mi(a,b/2)*mi(a,b/2))%mod)*a)%mod;
	else
		return (mi(a,b/2)*mi(a,b/2))%mod;
}

int main()
{
	long long n,m;
	cin>>n>>m;
	cout<<mi(mi(2,m)-1,n)<<endl;
	return 0;
}
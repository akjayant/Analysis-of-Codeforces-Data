#include<bits/stdc++.h>
using namespace std;
long long f[100001];
int main()
{
	long long n,m;
	cin>>n>>m;
	f[1]=1;
	f[2]=2;
	for(long long i=3;i<=max(n,m);i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]%=1000000007;
	}
	long long k=f[n]+f[m]-1;
	k%=1000000007;
	k*=2;
	k%=1000000007;
	cout<<k;
	return 0;
}

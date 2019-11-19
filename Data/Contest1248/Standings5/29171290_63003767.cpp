#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int mod=1E9+7;
long long a[200000],b[200000],c[200000];
int main()
{
	int n,m;
	cin>>n>>m;
	a[1]=2,a[2]=4;
	b[1]=0,b[2]=2;
	c[1]=0,c[2]=2;
	for(int i=3;i<=max(n,m);i++)
	{
		b[i]=(b[i-1]+b[i-2])%mod;
		a[i]=(a[i-1]+a[i-2])%mod;
		c[i]=(c[i-1]+b[i])%mod;
	}
	cout<<(c[n]%mod+a[m]%mod)%mod<<endl;
	return 0;
}

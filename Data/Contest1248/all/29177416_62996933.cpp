#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005];
typedef long long ll;
const ll mod=1e9+7;
int main()
{
	int n,m;
	a[1]=2;
	a[2]=4;
	for(int i=3;i<=1e5+5;i++)
	{
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	
	cin>>n>>m;
	ll ans=(a[n]+a[m]-2)%mod;
	cout<<ans<<endl;
	return 0;
}

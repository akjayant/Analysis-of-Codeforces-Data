#include <bits/stdc++.h>

using namespace std;
#define int long long
#define Mod 1000000007
int n,m;
int a[100005];

signed main()
{
	cin >> n >> m;
	a[1]=2;
	a[2]=4;
	for(int i=3;i<=100000;++i)
	{
		a[i]=a[i-1]+a[i-2];
		a[i]%=Mod;
	}
	cout << (a[n]+a[m]-2)%Mod;
	return 0;
}
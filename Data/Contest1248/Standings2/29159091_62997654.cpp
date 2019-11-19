#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int a[100001],n=0,m=0;
int b[100001];
signed main()
{	
	cin >> n >> m;	
	a[1] = 2;
	a[2] = 4;
	for (int i=3; i<=100000; i++)
		a[i] = (a[i-1]+a[i-2])%MOD;	
	if (n==1 || m==1)
	{
		cout << a[n+m-1];
	}		
	else
	{
		b[1] = a[n];
		b[2] = a[n]+2;
		b[3] = a[n]+4;	
		for (int i=4; i<=m; i++)
		{
			b[i] = (b[i-1]+(MOD+b[i-1]-b[i-3]))%MOD;
		}
		cout << b[m];
	}			
}
#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

long long poww(long long b,long long p)
{
	if(p==0) return 1;
	if(p&1) return (poww(b,p-1)*b)%MOD;
	return poww((b*b)%MOD,p/2);
}

int main()
{
	int n,m;
	cin >> n >> m;
	cout << poww((poww(2,m)-1+MOD)%MOD,n) << endl;
}
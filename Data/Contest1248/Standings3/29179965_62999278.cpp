#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const int maxn = 1e5+5;
ll f[maxn]={2,2};

int main()
{
	int n,m;
	for(int i=2;i<=100000;i++) f[i] = (f[i-1] + f[i-2]) % mod;
	scanf("%d%d",&n,&m);
	printf("%lld\n",(f[n]-2+f[m]+mod)%mod);
	return 0;
}
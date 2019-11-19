#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int n,m;
int f[100001];
int main()
{
	scanf("%d%d",&n,&m);
	f[1]=2;
	f[2]=4;
	for(int i=3;i<=max(n,m);i++)
	f[i]=(f[i-1]+f[i-2])%mod;
	printf("%d",(f[n]+f[m]-2)%mod);
	return 0;
}
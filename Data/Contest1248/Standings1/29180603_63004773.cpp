#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int mod=1000000007;
int n,m,a[100005],b[100005];
int main()
{
	scanf("%d%d",&n,&m);
	a[1]=a[2]=2,b[1]=2,b[2]=4;
	for(int i=2;i<=max(n,m)+1;i++)
		a[i]=(a[i-1]+a[i-2])%mod,b[i]=(a[i]+b[i-1])%mod;
	printf("%d\n",(a[n+1]+b[m-1])%mod);
	return 0;
}
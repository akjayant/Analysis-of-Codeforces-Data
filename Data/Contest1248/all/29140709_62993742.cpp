#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int n,m;
long long f[100010],a[100010],b[100010];
int main()
{
	scanf("%d %d",&n,&m);
	f[1]=2; f[2]=2;
	for (int i=3;i<=100005;i++)
		f[i]=(f[i-1]+f[i-2])%mo;
	a[1]=2;
	for (int i=2;i<=n;i++)
		a[i]=(a[i-1]+f[i-1])%mo;
	b[1]=a[n];
	for (int i=2;i<=m;i++)
		b[i]=(b[i-1]+f[i-1])%mo;
	printf("%lld\n",b[m]);
}
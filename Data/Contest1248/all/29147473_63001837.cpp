#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1000005
#define INF 0x3f3f3f3f
#define mod 1000000007
LL a1[N],a2[N];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(n<m)
		swap(n,m);
	a1[1]=2;
	for(int i=2;i<=n+1;i++)
		a1[i]=(a1[i-1]+a1[i-2])%mod;
	a2[1]=a1[n+1];
	for(int i=2;i<=m;i++)
		a2[i]=(a2[i-1]+a1[i-1])%mod;
	printf("%lld",a2[m]);
}

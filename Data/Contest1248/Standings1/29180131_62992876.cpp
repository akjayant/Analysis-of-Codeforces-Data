#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],b[N];

int main(){

	int n,m;
	scanf("%d%d",&n,&m);
	a[1]=1;a[2]=1;
	for(int i=3;i<=m;i++)a[i]=(a[i-1]+a[i-2])%mod;
	for(int i=2;i<=m;i++)a[i]=(a[i]+a[i-1])%mod;
	b[1]=1;b[2]=2;
	for(int i=3;i<=n;i++)b[i]=(b[i-1]+b[i-2])%mod;
	printf("%d\n",(a[m-1]+b[n])%mod*2%mod);
}
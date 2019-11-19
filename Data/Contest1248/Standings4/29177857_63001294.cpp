#include<bits/stdc++.h>
#define N 100005
#define MOD 1000000007
typedef long long LL;
LL F[N];
int n,m;
int main(){
	F[0]=1;F[1]=1;
	for (int i=2;i<=N-5;i++)F[i]=(F[i-1]+F[i-2])%MOD;
	scanf("%d%d",&n,&m);
	printf("%lld\n",2*((F[n]+F[m]-1)%MOD)%MOD);
	return 0;
}
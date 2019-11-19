#include<bits/stdc++.h>
using namespace std;
#define N 1000001
#define Mod 1000000007
int n,m;long long f[N],s;
int main(){
	scanf("%d%d",&n,&m),f[1]=1,f[2]=2;
	for(int i=3;i<=n||i<=m;++i)f[i]=(f[i-1]+f[i-2])%Mod;
	s=(f[n]+f[m]-1)%Mod,printf("%lld\n",((s+s)%Mod+Mod)%Mod);
	return 0;
}
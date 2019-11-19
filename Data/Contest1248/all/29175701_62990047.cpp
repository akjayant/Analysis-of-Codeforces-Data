#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int f[100010];
int main(){
	f[0]=f[1]=2;
	int n,m;
	scanf("%d%d",&n,&m);
	int t=max(n,m);
	for(int i=2;i<=t;i++)f[i]=(f[i-1]+f[i-2])%mod;
	printf("%d\n",((f[n]+f[m])%mod+1000000005)%mod);
}
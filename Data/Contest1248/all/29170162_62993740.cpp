#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,nm,mod=1e9+7,f[111111];
signed main(){
	scanf("%d%d",&n,&m),nm=max(n,m),f[0]=f[1]=1;
	for(int i=2;i<=nm;i++)f[i]=f[i-1]+f[i-2],f[i]%=mod;
	int ans=f[m];
	for(int i=0;i<n-1;i++)ans+=f[i],ans%=mod;
	printf("%I64d",ans*2%mod);
}

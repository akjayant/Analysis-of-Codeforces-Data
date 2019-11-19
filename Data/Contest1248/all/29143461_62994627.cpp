#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod=1e9+7;

int f[100005],ans,n,m;

signed main(){
	cin>>n>>m;
	f[1]=f[2]=1;
	for(int i=3;i<=max(n+1,m+1);i++) f[i]=(f[i-1]+f[i-2])%mod;
	ans=2*((f[n+1]+f[m+1]-1)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}
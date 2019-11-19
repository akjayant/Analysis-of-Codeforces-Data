#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int _=1e5+7,mod=1e9+7;
int read() {int x;scanf("%d",&x);return x;}
ll n,m,f[_],g[_];
int main() {
	cin>>n>>m;
	if(n<m) swap(n,m);
	f[1]=2,f[2]=4;
	for(int i=3;i<=n+1;++i) f[i]=(f[i-1]+f[i-2])%mod;
	g[1]=f[n];
	g[2]=(f[n]+2)%mod;
	for(int i=3;i<=m;++i) g[i]=(g[i-1]+f[i]-f[i-1])%mod,g[i]=(g[i]%mod+mod)%mod;
	cout<<g[m]<<"\n";
	return 0;
}
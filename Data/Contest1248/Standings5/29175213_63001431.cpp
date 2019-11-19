#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+10;
int n,m;
ll f[maxn];

int main(){
	scanf("%d%d",&n,&m);
	f[0]=0;
	f[1]=2;
	f[2]=4;
	for(int i=3;i<=100000;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	ll ans=(f[n]+f[m]-2)%mod;
	printf("%lld\n",ans);
	return 0;
}
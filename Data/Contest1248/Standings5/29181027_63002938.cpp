#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int t1,t2;
int t[100010];
signed main(){
	scanf("%lld%lld",&t1,&t2);
	t[1]=2,t[2]=4;
	for(int i=3;i<=max(t1,t2);i++) t[i]=(t[i-1]+t[i-2])%mod;
	printf("%lld",((t[t1]+t[t2]-2)%mod+mod)%mod);
}
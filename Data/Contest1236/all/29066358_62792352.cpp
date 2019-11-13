#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
const int INF = 0x3f3f3f3f;
const int mod=1e9+7;
ll qp(ll k,ll x){
	ll res=1;
	while(x){
		if(x&1) res=res*k%mod;
		k=k*k%mod;
		x>>=1;
	}
	return res;
}
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll res=qp(2,m)-1;
	res=qp(res,n);
	printf("%lld\n",res);
}
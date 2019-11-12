// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, mod=1e9+7;

int pw(int x,int y){
	if(y==0)return 1;if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	int n,m;scanf("%lld%lld",&n,&m);
	LL p = pw(2,m)-1;
	p = (p+mod)%mod;
	printf("%lld\n",pw(p,n));

	return 0;
}

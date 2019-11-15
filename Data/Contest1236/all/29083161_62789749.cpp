#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long mod = 1000000007;

long long power(long long a, long long b){
	long long ans = 1;
	while(b){
		if(b&1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}

int main(){
	scanf("%lld%lld",&n,&m);

	printf("%lld\n",power(power(2,m)-1, n));

	
	return 0;
}


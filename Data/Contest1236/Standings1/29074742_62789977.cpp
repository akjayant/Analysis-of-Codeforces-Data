#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
inline int read(){
	register int res=0, c;
	while(c=getchar(), c<'0'||c>'9');
	do{
		res=(res*10)+(c^48);
	} while(c=getchar(), c>='0'&&c<='9');
	return res;
}
const int mod = 1e9+7;
int pow(int n, int k){
	int res = 1;
	while(k){
		if(k&1)res = 1ll * res * n % mod;
		n = 1ll * n * n % mod;
		k >>= 1;
	}
	return res;
}
int main() {
	int N=read(), M=read();
	int ans = (pow(2, M)+mod-1)%mod;
	ans = pow(ans, N);
	if(ans<0)ans+=mod;
	printf("%d\n", ans);
	return 0;
}
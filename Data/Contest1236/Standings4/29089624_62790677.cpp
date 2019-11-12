#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
 
using namespace std;
 
#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll; 

ll mod=1000000007;

long long power(long long n, long long p, long long k) {//n^k(mod p)
	if (!k) return 1;
	long long a = power(n,p, k>>1);
	a = a * a%p;
	if (k & 1) a = a * n%p;
	return a;
}
int main(){
	int n,m;
	cin >> n >> m;
	ll ans=(power(2,mod,m)-1)%mod;
	ans=power(ans,mod,n);
	printf("%lld\n",ans);
}
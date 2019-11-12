#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

int main() {
	ll n, m;
	scanf("%I64d%I64d", &n, &m);
	ll sol = 1LL;
	ll p5000 = 1LL;
	for (int i=0 ; i<5000 ; i++) p5000 = (p5000*2LL) % MOD;
	while (m>=5000LL) {
		m-=5000LL;
		sol = (sol*p5000) % MOD;
	}
//	cout <<"oveed"<<endl;
	for (int i=0 ; i<m ; i++) sol = (sol * 2LL) % MOD;
//	cout <<"asd\n";
//	cout <<sol<<endl;
	sol = (sol + MOD - 1) % MOD;
	ll P5 = 1LL;
//	cout <<1<<endl;
	for (int i=0 ; i<5000 ; i++) P5 = (P5*sol) % MOD;
	ll rj = 1LL;
//cout <<"oveed"<<endl;
	while (n>=5000LL) {
		n-=5000LL;
		rj = (rj * P5) % MOD;
	}
//	cout <<"nigad"<<endl;
	for (int i=0 ; i<n ; i++) rj = (rj*sol) % MOD;
//		cout <<123412<<endl;
	cout <<rj<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const long long MODULO = 1000000007;

long long getPow(long long base, int exponent) {
	if (exponent == 0) return 1;
	if (exponent == 1) return base;
	long long pow = getPow(base, exponent / 2);
	if (exponent % 2 == 1) {
		return (((base * pow) % MODULO) * pow) % MODULO;
	}
	return (pow * pow) % MODULO;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, m;
	cin >> n >> m;
	int ret = getPow((getPow(2, m) - 1) , n);
	cout << ret;
	return 0;
}

#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MOD 1000000007
using namespace std;
 
int n, m;

int pw(int a, int n) {
	int b = 1, tmp = 1;
	for (; b <= n; b *= 2) {
		if (b & n) tmp = (tmp * a) % MOD;
		a = (a * a) % MOD;
	}
	return tmp;
}

signed main() {
	Hina;
	cin >> n >> m;
	cout << pw(pw(2, m)-1, n) << endl;
	return 0;
}
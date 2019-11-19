#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define Push push_back
typedef long long lli;
typedef pair<lli, lli> pll;
typedef vector<lli> vcL;
typedef vector<pll> vPL;

const lli mod = 1E9 + 7;

int main() {
	lli n, m, ans = 0;
	cin >> n >> m;
	
	lli matrix[2][2] = {{1, 0}, {0, 1}};
	lli BASE[2][2] = {{1, 1}, {1, 0}};
	lli tmp[2][2];
	
	while (n) {
		if (n & 1) {
			/// matrix multiply
			tmp[0][0] = (matrix[0][0] * BASE[0][0] + matrix[1][0] * BASE[0][1]) % mod;
			tmp[0][1] = (matrix[0][1] * BASE[0][0] + matrix[1][1] * BASE[0][1]) % mod;
			tmp[1][0] = (matrix[0][0] * BASE[1][0] + matrix[1][0] * BASE[1][1]) % mod;
			tmp[1][1] = (matrix[0][1] * BASE[1][0] + matrix[1][1] * BASE[1][1]) % mod;
			matrix[0][0] = tmp[0][0];
			matrix[0][1] = tmp[0][1];
			matrix[1][0] = tmp[1][0];
			matrix[1][1] = tmp[1][1];
		}
		n >>= 1;
		/// BASE multiply
		tmp[0][0] = (BASE[0][0] * BASE[0][0] + BASE[1][0] * BASE[0][1]) % mod;
		tmp[0][1] = (BASE[0][1] * BASE[0][0] + BASE[1][1] * BASE[0][1]) % mod;
		tmp[1][0] = (BASE[0][0] * BASE[1][0] + BASE[1][0] * BASE[1][1]) % mod;
		tmp[1][1] = (BASE[0][1] * BASE[1][0] + BASE[1][1] * BASE[1][1]) % mod;
		BASE[0][0] = tmp[0][0];
		BASE[0][1] = tmp[0][1];
		BASE[1][0] = tmp[1][0];
		BASE[1][1] = tmp[1][1];
	}
	
	ans += matrix[0][0];
	
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	BASE[0][0] = 1;
	BASE[0][1] = 1;
	BASE[1][0] = 1;
	BASE[1][1] = 0;
	
	while (m) {
		if (m & 1) {
			/// matrix multiply
			tmp[0][0] = (matrix[0][0] * BASE[0][0] + matrix[1][0] * BASE[0][1]) % mod;
			tmp[0][1] = (matrix[0][1] * BASE[0][0] + matrix[1][1] * BASE[0][1]) % mod;
			tmp[1][0] = (matrix[0][0] * BASE[1][0] + matrix[1][0] * BASE[1][1]) % mod;
			tmp[1][1] = (matrix[0][1] * BASE[1][0] + matrix[1][1] * BASE[1][1]) % mod;
			matrix[0][0] = tmp[0][0];
			matrix[0][1] = tmp[0][1];
			matrix[1][0] = tmp[1][0];
			matrix[1][1] = tmp[1][1];
		}
		m >>= 1;
		/// BASE multiply
		tmp[0][0] = (BASE[0][0] * BASE[0][0] + BASE[1][0] * BASE[0][1]) % mod;
		tmp[0][1] = (BASE[0][1] * BASE[0][0] + BASE[1][1] * BASE[0][1]) % mod;
		tmp[1][0] = (BASE[0][0] * BASE[1][0] + BASE[1][0] * BASE[1][1]) % mod;
		tmp[1][1] = (BASE[0][1] * BASE[1][0] + BASE[1][1] * BASE[1][1]) % mod;
		BASE[0][0] = tmp[0][0];
		BASE[0][1] = tmp[0][1];
		BASE[1][0] = tmp[1][0];
		BASE[1][1] = tmp[1][1];
	}
	
	ans += matrix[0][0];
	ans -= 1;
	
	ans *= 2;
	ans %= mod;
	ans += mod;
	ans %= mod;
	
	cout << ans << "\n";
	
	// for (int i = 1; i <= 15; ++i) {
		// int ans = 0;
		// for (int j = 0; j < (1<<i); ++j) {
			// bool flag = true;
			// for (int k = 1; k < i-1; ++k) {
				// if ((j & (1 << k - 1)) == 0 and (j & (1 << k)) == 0 and (j & (1 << k + 1)) == 0) {
					// flag = false;
					// break;
				// }
				// if ((j & (1 << k - 1)) and (j & (1 << k)) and (j & (1 << k + 1))) {
					// flag = false;
					// break;
				// }
			// }
			// if (flag) {
				//// cout << j << "\n";
				// ++ans;
			// }
		// }
		// cout << i << ": " << ans << "\n";
	// }
	
	return 0;
}
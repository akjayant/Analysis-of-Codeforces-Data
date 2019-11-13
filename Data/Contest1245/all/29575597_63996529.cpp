/**
 * author:  apikdech
 * created: 01.11.2019 21:38:44
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		if (__gcd(a, b) == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, tmp, sup, res = 0, cnt = 0;
	cin >> n; tmp = n;
	sup = sqrt(n) + 1;
	if (n == 1) cout << "1" << endl;
	else {
		for (int i = 2; i < sup; i++) {
			if (n % i == 0) {
				res = i; cnt++;
				while (n % i == 0) n = n / i;
			}
		}
		if (cnt == 0) cout << tmp << endl;
		else if (n == 1 && cnt == 1) cout << res << endl;
		else cout << "1" << endl; 
	}
	return 0;
}
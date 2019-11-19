#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second

//CHECK FOR N = 1 OR OTHER DUMB TESTS 

using namespace std;

int t, a, b, c, d, k;

int main() {
	//ifstream cin("tst.in");
	//ofstream out("tst.out");
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d >> k;
		bool flag = 0;
		for (int i = 1; i <= k; i++) {
			if (i * c >= a && (k - i) * d >= b) {
				flag = 1;
				cout << i << ' ' << k - i << '\n';
				break;
			}
		}
		
		if (flag == 0)
			cout << -1 << '\n';
	}	
	return 0;
}
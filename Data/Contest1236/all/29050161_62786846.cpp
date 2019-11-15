#include <bits/stdc++.h>
#define MOD (ll)(1e9 + 7)
#define MAX (ll)(1e6 + 4)
#define INF (ll)(1e9 + 1)
using namespace std;
using ll =  long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ma = 0;
		for (int i = 0; i <= a; i++) {
			if (i * 2 > b) {
				break;	
			}
			int mm = 3 * i;
			int cb = b - i * 2;
			mm += min (cb, c / 2) * 3;
			ma = max (mm, ma);
		}
		cout << ma << "\n";
	}
}


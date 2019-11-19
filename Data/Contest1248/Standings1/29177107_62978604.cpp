#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		ll evenp=0, oddp = 0,evenq=0, oddq=0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x % 2 == 0) evenp++;
			else oddp++;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			if (x % 2 == 0) evenq++;
			else oddq++;
		}
		cout << evenp * evenq + oddp * oddq << endl;
	}

}
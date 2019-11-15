#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
	int t, a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		bool finite = __gcd(a, b) == 1;

		if(!finite) cout << "infinite" << endl;
		else cout << "finite" << endl;
	}

	return 0;
}
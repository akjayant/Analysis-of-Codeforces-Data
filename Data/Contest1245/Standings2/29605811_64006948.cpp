#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second

#define pb push_back

int gcd(int a, int b) {
	if (b > a) swap(a, b);

	return b ? gcd(b, a % b) : a;
}

int main() {
	int t;
	cin >> t;
	while (t-->0) {
		int a, b;
		cin >> a >> b;
		if(gcd(a, b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	return 0;
}

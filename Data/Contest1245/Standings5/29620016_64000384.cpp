#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pii;

int gcd(int a, int b) {
	return !b? a: gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	int q, a, b;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (gcd(a, b) == 1)
			cout << "Finite\n";
		else
			cout << "InFinite\n";
	}
}

#include <bits/stdc++.h>

#define sz(a) int(a.size())
using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		puts(gcd(a, b) == 1 ? "Finite" : "Infinite");
	}
}

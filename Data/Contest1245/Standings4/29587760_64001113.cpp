#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int t, a, b;

#define PI 3.14159265358979323846

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == 1 || b == 1 || gcd( a, b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;



void prepare() {
	
}

void read() {		
}

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b % a, a);
}

void solve() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (gcd(a, b) == 1) {
			printf("Finite\n");
		} else {
			printf("Infinite\n");
		}
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	read();
	solve();
	
	return 0;
}




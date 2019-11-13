#include <iostream>
using namespace std;

int t;
int a, b;

int gcd(int a, int b);

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		if (gcd(a, b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}

	return 0;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

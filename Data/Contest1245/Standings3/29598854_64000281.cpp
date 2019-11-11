#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int T, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		if (gcd(a, b) == 1) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}
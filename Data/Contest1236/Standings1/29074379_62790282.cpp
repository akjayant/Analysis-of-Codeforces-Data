#include <bits/stdc++.h>
#include <stdint.h>
#define mk make_pair
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int l = n / 2;
		int r = n - n / 2;
		for (int j = 1; j <= l; j++) {
			printf("%d ", i + (j - 1) * n);
		}
		for (int j = 1; j <= r; j++) {
			printf("%d ", n - i + 1 + (n - j) * n);
		}
		puts("");
	}
}
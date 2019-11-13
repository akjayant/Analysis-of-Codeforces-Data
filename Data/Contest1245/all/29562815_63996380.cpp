#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a,b;
		scanf("%d%d", &a, &b);
		if (__gcd(a, b) == 1) {
			printf("Finite\n");
		} else {
			printf("Infinite\n");
		}
	}
	return 0;
}
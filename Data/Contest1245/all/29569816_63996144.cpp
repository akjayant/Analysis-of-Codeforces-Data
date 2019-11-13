#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int t, a, b;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		puts(__gcd(a, b) == 1 ? "Finite" : "Infinite");
	}
	return 0;
}

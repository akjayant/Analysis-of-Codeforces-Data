#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;

int main() {
	int t;

	scanf("%d", &t);

	while(t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int tmp = min(b, c / 2);
		int ans = tmp + 2 * tmp;
		b -= tmp, c -= 2 * tmp;
		tmp = min(a, b / 2);
		printf("%d\n", ans + tmp * 3);
	}

}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 20101009;
const int maxn = 1e4 + 10;
int num[1100];
int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		memset(num, 0, sizeof(num));
		int n;
		scanf("%d", &n);
		for (int i = 1, x; i <= n; i++)
			scanf("%d", &x), num[x]++;
		int ans = 0;
		for (int i = n; i >= 0&&!ans; i--) {
			num[i] += num[i + 1];
			if (num[i] >= i)
				ans = i;
		}
		printf("%d\n", ans);

	}
}
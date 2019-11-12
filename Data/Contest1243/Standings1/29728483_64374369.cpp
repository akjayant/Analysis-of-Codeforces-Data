#include <bits/stdc++.h>
using namespace std;

int v[1123];

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		int ans = 0;
		for (int i = 1000; i >= 1; i--) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (v[j] >= i) cnt++;
			}
			if (cnt >= i) {
				printf("%d\n", i);
				break;
			}
		}

	}

}

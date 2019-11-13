#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _CONSOLE
	freopen("t.in", "r", stdin);
#endif

	int n, c = 0;
	scanf("%d", &n);
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		if (i & 1) for (int j = 0; j < n; ++j) a[j].push_back(++c);
		else for (int j = n - 1; ~j; --j) a[j].push_back(++c);
	}
	for (int i = 0; i < n; ++i) {
		for (int j : a[i]) printf("%d ", j);
		puts("");
	}
}
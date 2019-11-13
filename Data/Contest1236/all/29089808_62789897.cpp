#include <bits/stdc++.h>

using namespace std;

int n;

int main( ) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			if (j & 1) printf("%d ", (j - 1) * n + i);
			else printf("%d ", (j - 1) * n + n - i + 1);
		puts("");
	}
	return 0;
}
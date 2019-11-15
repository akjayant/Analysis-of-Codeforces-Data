#include <bits/stdc++.h>
using namespace std;
const int N = 305;

int n, cnt, a[N][N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		if(i & 1)
			for(int j = 1; j <= n; ++j)
				a[i][j] = ++cnt;
		else
			for(int j = n; j; --j)
				a[i][j] = ++cnt;
	}
	for(int j = 1; j <= n; ++j)
		for(int i = 1; i <= n; ++i)
			printf("%d%c", a[i][j], " \n"[i == n]);
	return 0;
}


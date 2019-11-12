#include <bits/stdc++.h>
using namespace std;
const int maxn=200050;
int a[500][500];
int main() {
	int n;
	scanf("%d", &n);
	int tot=0;
	for(int j = 1; j <= n; ++j) {
		if(j&1) {
			for(int i = 1; i <= n; ++i) a[i][j]=++tot;
		} else {
			for(int i = n; i >= 1; --i) a[i][j]=++tot;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			printf("%d%s", a[i][j], j==n?"\n":" ");
		}
	}
	return 0;
}

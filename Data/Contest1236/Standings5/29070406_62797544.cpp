#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn (333)
int g[maxn][maxn];
int main()
{
	int n; scanf("%d", &n);
	int k = n * n;
	for(int i = 1; i <= n; i++) {
		if(i % 2) for(int j = 1; j <= n; j++) {
			g[i][j] = k--;
		} else for(int j = n; j >= 1; j--) {
			g[i][j] = k--;
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(j > 1) putchar(' ');
			printf("%d", g[j][i]);
		}
		putchar('\n');
	}
	return 0;
}

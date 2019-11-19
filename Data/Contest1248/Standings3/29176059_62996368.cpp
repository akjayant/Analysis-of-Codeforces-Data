#include <bits/stdc++.h>
using namespace std;
const int yzh = 1e9+7, N = 100000+5;

int n, m, f[N]; 
 
int main() {
	scanf("%d%d", &n, &m);
	if (n < m) swap(n, m);
	f[1] = 2;
	for (int i = 2; i <= n; i++) f[i] = (f[i-1]+f[i-2])%yzh;
	for (int i = 2; i <= n; i++) f[i] = (f[i]+f[i-1])%yzh;
	printf("%d\n", (f[m-1]+f[n-1]+2)%yzh);
	return 0;
}

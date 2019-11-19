#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
const int maxn = 1e5 + 5;
int n, m;
long long a[maxn];
int main() {
	cin >> n >> m;
	if(n < m) swap(n, m);
	a[1] = 2;
	a[2] = 2;
	for(int i = 3; i <= n + 1; ++i) a[i] = (a[i - 1] + a[i - 2]) % P;
	long long s = 0;
	for(int i = 1; i < m; ++i) s = (s + a[i]) % P; 
	long long tmp = a[n + 1];
//	printf("a[%d] = %d\n", n, a[n]);
	tmp = (tmp + s) % P;
//	tmp = (tmp + a[m - 2] + 2) % P;
	printf("%lld\n", tmp);
	return 0;
}
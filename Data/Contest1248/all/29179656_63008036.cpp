#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define mod 1000000007
using namespace std;
LL read() {
	LL k = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
		k = k * 10 + c - 48, c = getchar();
	return k * f;
}
LL f[100010], f2[100010];
int main() {
	int n = read(), m = read();
	if(n > m) swap(n, m);
	f[0] = f[1] = 2;
	for(int i = 2; i <= m; ++i) f[i] = (f[i-1] + f[i-2]) % mod;
	f2[1] = f[n];
	for(int i = 2; i <= m; ++i) {
		f2[i] = (f2[i-1] + f[i-2]) % mod;
	}
	cout << f2[m];
	return 0;
}
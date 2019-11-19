#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
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
LL a[100010];
int main() {
	int n = read();
	LL sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; ++i) a[i] = read(), sum2 += a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n/2; ++i) sum1 += a[i];
	sum2 -= sum1;
	sum1 *= sum1, sum2 *= sum2;
	printf("%lld\n", sum1 + sum2);
	return 0;
}
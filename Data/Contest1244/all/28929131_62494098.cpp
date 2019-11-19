#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define ls p << 1
#define rs p << 1 | 1
#define mid (l + r >> 1)
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
LL a[100010], cnt = 1;
struct zzz {
	LL k, tot;
}q[100010];
int main() {
	LL n = read(), k = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	sort(a+1, a+n+1);
	q[1].k = a[1]; q[1].tot = 1;
	for(int i = 2; i <= n; ++i) {
		if(a[i] != a[i-1]) {
			q[++cnt].k = a[i]; q[cnt].tot = 1;
		}
		else ++q[cnt].tot;
	}
	int l = 1, r = cnt;
	while(k && l < r) {
		if(q[l].tot < q[r].tot) {
			if((q[l+1].k - q[l].k) * q[l].tot <= k) {
				k -= (q[l+1].k - q[l].k) * q[l].tot;
				++l; q[l].tot += q[l-1].tot;
			}
			else {
				q[l].k += (k / q[l].tot);
				k = 0;
			}
		}
		else {
			if((q[r].k - q[r-1].k) * q[r].tot <= k) {
				k -= (q[r].k - q[r-1].k) * q[r].tot;
				--r; q[r].tot += q[r+1].tot;
			}
			else {
				q[r].k -= (k / q[r].tot);
				k = 0;
			}
		}
	}
	cout << q[r].k - q[l].k;
	return 0;
}
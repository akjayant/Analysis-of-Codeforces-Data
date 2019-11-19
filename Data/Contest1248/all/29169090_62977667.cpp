#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
long long cnt1, cnt2, cnt3, cnt4;

void Read() {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int p;
		scanf("%d", &p);
		if (p & 1) cnt2++;
		else cnt1++;
	}
	scanf("%d", &m);
	for (int i = 1;i <= m;i++) {
		int q;
		scanf("%d", &q);
		if (q & 1) cnt4++;
		else cnt3++;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cnt1 = cnt2 = cnt3 = cnt4 = 0;
		Read();
		printf("%I64d\n", cnt2 * cnt4 + cnt1 * cnt3);
	}
	return 0;
}

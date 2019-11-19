#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long a[100005];

void Read() {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) scanf("%I64d", &a[i]);
}

void Solve() {
	sort(a + 1, a + n + 1);
	long long dis1 = 0, dis2 = 0;
	for (int i = 1;i <= (n >> 1);i++) dis1 += a[i];
	for (int i = (n >> 1) + 1;i <= n;i++) dis2 += a[i];
	printf("%I64d", dis1 * dis1 + dis2 * dis2); 
}

int main() {
	Read();
	Solve();
	return 0;
}

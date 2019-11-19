#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100000+5;

int n, a[N];
ll x, y;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for (int i = 1; i <= n/2; i++) x += a[i];
	for (int i = n/2+1; i <= n; i++) y += a[i];
	printf("%I64d\n", x*x+y*y);
	return 0;
}

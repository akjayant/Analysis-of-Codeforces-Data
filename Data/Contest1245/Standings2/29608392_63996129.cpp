#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
	int x, y;
	scanf("%d%d", &x, &y);
	if (__gcd(x, y) == 1) puts("Finite");
	else puts("Infinite");}
	return 0;
}
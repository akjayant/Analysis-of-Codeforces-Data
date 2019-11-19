#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a,b,c,d,k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int br = (a+c-1) / c + (b+d-1) / d;
		if (br>k) printf("-1\n");
		else printf("%d %d\n", (a+c-1) / c, (b+d-1) / d);
	}
	return 0;
}
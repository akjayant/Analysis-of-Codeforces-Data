#include <iostream>
#include <cstdio>
using namespace std;

int t, a, b, c, d, k, t1, t2;
int main()
{
	cin >> t;
	while (t--) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		t1 = (a + c - 1) / c;
		t2 = (b + d - 1) / d;
		if (t1 + t2 > k) puts("-1");
		else printf("%d %d\n", t1, t2);
	}
    return 0;
}
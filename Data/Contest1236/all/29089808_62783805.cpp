#include <bits/stdc++.h>

using namespace std;

int t, a, b, c;
int main( ) {
	scanf("%d", &t);
	while (t --){
		scanf("%d %d %d", &a, &b, &c);
		int tmp = min(b, c / 2);
		b -= tmp;
		int tmp2 = min(a, b / 2);
		printf("%d\n", 3 * (tmp + tmp2));
	}
	return 0;
}
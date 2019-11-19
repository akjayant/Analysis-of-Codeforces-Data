#define make_pair mp
#define emplace_back pb
#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
const int N = 1e5 + 5;
int t, a, b, c, d, k;
int main()
{
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x = (a + c - 1) / c;
		int y = (b + d - 1) / d;
		if(x + y > k) printf("-1\n");
		else printf("%d %d\n", x, y);
	}
	return 0;
}

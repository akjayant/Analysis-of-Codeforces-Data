#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int T; cin >> T; while(T--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		int ans = 0;
		int x = min(b, c / 2);
		ans += x * 3;
		b -= x;
		int y = min(a, b / 2);
		ans += y * 3;
		printf("%d\n", ans);
	}
	return 0;
}

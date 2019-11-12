#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#include <cassert>
#include <complex>

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
#define memset0(x) memset(x, 0, sizeof(x))
#define memsetM1(x) memset(x, -1, sizeof(x))
#define memsetINF(x) memset(x, INF, sizeof(x))

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int startTime = clock();
#endif
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int ans = 0;
		while (c >= 2 && b >= 1)
		{
			ans += 3;
			c -= 2, b--;
		}
		while (b >= 2 && a >= 1)
		{
			ans += 3;
			b -= 2, a--;
		}
		printf("%d\n", ans);
	}


#ifndef ONLINE_JUDGE
	printf("Time = %dms\n", clock() - startTime);
#endif
	return 0;
}

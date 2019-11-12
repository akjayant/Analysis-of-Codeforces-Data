#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const long long LINF = 1e18 + 1;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int ans = 0;
		int t = min(b, c / 2);
		ans += t*3;
		b -= t;
		int t2 = min(a, b / 2);
		ans += 3*t2;
		printf("%d\n", ans);
	}
	
	return 0;
}
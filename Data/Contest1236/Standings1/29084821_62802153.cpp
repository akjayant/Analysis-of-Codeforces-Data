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

const int MAXN = 305;
vector<int> arr[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int startTime = clock();
#endif
	int n;
	scanf("%d", &n);
	int index = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int id = j;
			if (i % 2 == 1)
			{
				id = n - 1 - j;
			}
			arr[id].push_back(index++);
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d%c", arr[i][j], j == n - 1 ? '\n' : ' ');
		}
	}

#ifndef ONLINE_JUDGE
	printf("Time = %dms\n", clock() - startTime);
#endif
	return 0;
}

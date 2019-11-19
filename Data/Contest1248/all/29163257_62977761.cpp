#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <ctime>
#include <utility>
#include <bitset>
#include <random>
#include <iostream>
#include <iterator>
#include <stack>
#include <list>
#include <fstream>

using namespace std;

const long long INF = numeric_limits<long long>::max();
const int MOD = 1000 * 1000 * 1000 + 7;
const int BASE = 257;
const double PI = 2 * acos(0.0);

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		vector<int> p(n);
		for (int j = 0; j < n; j++)
			scanf("%d", &p[j]);
		int m;
		scanf("%d", &m);
		vector<int> q(m);
		for (int j = 0; j < m; j++)
			scanf("%d", &q[j]);
		int o1 = 0, o2 = 0, e1 = 0, e2 = 0;
		for (int j = 0; j < n; j++)
		{
			if (p[j] % 2 == 0)
				e1++;
			else
				o1++;
		}
		for (int j = 0; j < m; j++)
		{
			if (q[j] % 2 == 0)
				e2++;
			else
				o2++;
		}
		printf("%I64d\n", (o1 * 1LL * o2) + (e1 * 1LL * e2));
	}
	return 0;
}

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
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int& i : a)
		scanf("%d", &i);
	sort(a.begin(), a.end());
	long long s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			s1 += a[i];
		else
			s2 += a[i];
	}

	printf("%I64d\n", s1 * s1 + s2 * s2);

	return 0;
}

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
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int needPen = a / c + !!(a % c);
		int needPencil = b / d + !!(b % d);
		if (needPen + needPencil <= k)
			cout << needPen << ' ' << needPencil << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}

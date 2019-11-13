#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("fast-math")

#include <math.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cassert>
#include <memory.h>
#include <functional>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#include <complex>
#include <fstream>
#include <climits>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned u;
typedef long double ld;
typedef vector<vector<int>> vvi;
typedef unsigned char uc;
typedef unsigned short us;
typedef complex<double> cd;

#define INF 1000000000
#define LLINF 1000000000000000000LL
#define EPS 1e-9l
#define pii pair<int, int>

const int DEBUG = 0;

mt19937 gen((u)chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma comment(linker, "/STACK:16777216")

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(cout.fixed);
	cout.precision(12);

#ifdef LOCAL
	auto START_TIME = chrono::high_resolution_clock::now();
#endif

	int test;
	cin >> test;

	while (test--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int res = 0;

		for (int i = 0; i <= 100; i++)
		{
			for (int j = 0; j <= 100; j++)
			{
				int ta = a - i;
				int tb = b - 2 * i - j;
				int tc = c - 2 * j;

				if (ta >= 0 && tb >= 0 && tc >= 0)
				{
					res = max(res, 3 * (i + j));
				}
			}
		}

		cout << res << "\n";
	}

#ifdef LOCAL
	cerr.precision(3);
	cerr << "\nWorking time: " << chrono::duration<double>(chrono::high_resolution_clock::now() - START_TIME).count()
		<< " sec.";
#endif
	return 0;
}
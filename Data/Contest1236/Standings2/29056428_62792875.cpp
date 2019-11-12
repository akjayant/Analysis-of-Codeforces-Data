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

const ll MOD = 1000 * 1000 * 1000 + 7;

ll binPow(ll a, int pow)
{
	ll res = 1;

	while (pow)
	{
		if (pow & 1)
			res = res * a % MOD;

		a = a * a % MOD;
		pow /= 2;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(cout.fixed);
	cout.precision(12);

#ifdef LOCAL
	auto START_TIME = chrono::high_resolution_clock::now();
#endif

	int n;
	cin >> n;

	vector<deque<int>> ost(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = n * i + 1; j <= n * i + n; j++)
		{
			ost[i].push_back(j);
		}
	}

	vvi have(n);
	int par = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (par == 0)
			{
				have[i].push_back(ost[j].front());
				ost[j].pop_front();
			}
			else
			{
				have[i].push_back(ost[j].back());
				ost[j].pop_back();
			}

			par ^= 1;
		}
	}

	/*int cnt = INF;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			int curCnt = 0;

			for (int x1 : have[i])
			{
				for (int x2 : have[j])
				{
					if (x1 > x2)
					{
						curCnt++;
					}
				}
			}

			cnt = min(cnt, curCnt);
		}
	}

	cout << cnt << "\n";*/

	for (vector<int>& nums : have)
	{
		for (int x : nums)
		{
			cout << x << " ";
		}

		cout << "\n";
	}

#ifdef LOCAL
	cerr.precision(3);
	cerr << "\nWorking time: " << chrono::duration<double>(chrono::high_resolution_clock::now() - START_TIME).count()
		<< " sec.";
#endif
	return 0;
}
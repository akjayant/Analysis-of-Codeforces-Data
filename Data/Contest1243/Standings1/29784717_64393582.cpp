#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include <queue>
#include <string>
#include <set>

typedef  long long lol;
using namespace std;

#define fori(i,j,k) for (int (i)=(j);(i) < (k);(i)++)
#define MOD 4294967296ULL
#define EPS 0.000000001


int main() {

#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	long long n;
	cin >> n;

	set<long long> divisors;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			divisors.insert(i);
			if (n / i > 1)
				divisors.insert(n / i);
		}
	}

	if (divisors.size() == 0)
	{
		cout << n;
		return 0;
	}

	long long min_dv = *divisors.begin();
	for (long long x : divisors)
	{
		if (x % min_dv != 0)
		{
			cout << 1;
			return 0;
		}
	}

	cout << min_dv;

	return 0;
}
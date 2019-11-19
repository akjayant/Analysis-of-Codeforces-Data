#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("Ofast")

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <random>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

using namespace std;

const long double PI = 3.14159265358979323846264338328;
const long long mx64 = 9223372036854775807;
const int mx32 = 2147483647;
const short int mx16 = 32767;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(25);

	long long n; cin >> n;
	long long nn = n;
	map<long long, int> ds;
	for (long long d = 2; d*d <= n; d++) {
		while (n % d == 0) {
			ds[d]++;
			n /= d;
		}
	}

	if (n > 1) {
		ds[n]++;
	}

	if (n == nn) {
		cout << n;
		return 0;
	}

	if (ds.size() == 1) {
		map<long long, int>::iterator tr = ds.begin();
		cout << tr->first;
		return 0;
	}
	cout << 1;
	//cout << "\n"; system("pause");
	return 0;
}
/*

*/
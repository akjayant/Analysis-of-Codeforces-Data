/*#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("Ofast")*/

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
//#include <random>
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
const long long mod_1 = 1000000007;
const long long mod_2 = 998244353;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(25);

	int t; cin >> t;
	while (t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int cnt_1 = (a + c - 1) / c;
		int cnt_2 = (b + d - 1) / d;
		if (cnt_1 + cnt_2 > k) {
			cout << "-1\n";
		}
		else {
			cout << cnt_1 << " " << cnt_2 << "\n";
		}
	}

	//cout << "\n"; system("pause");
	return 0;
}
/*

*/
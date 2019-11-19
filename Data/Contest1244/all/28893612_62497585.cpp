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

	long long n; cin >> n;
	long long k; cin >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	long long ans = a[n - 1] - a[0];

	long long L = 0;
	long long R = n - 1;
	while (true)
	{
		if (!k) {
			break;
		}

		while (L < n - 1 && a[L] == a[L + 1]) { L++; }
		while (R > 0 && a[R - 1] == a[R]) { R--; }

		if (L >= R) {
			break;
		}

		long long cnt_L = L + 1;
		long long cnt_R = n - R;

		/*if (L == R - 1) {
			if (cnt_L < cnt_R) {

			}
			else {

			}
			break;
		}*/

		long long d_L = a[L + 1] - a[L];
		long long d_R = a[R] - a[R - 1];
		if (cnt_L < cnt_R) {
			if (k >= cnt_L * d_L) {
				k -= cnt_L * d_L;
				ans = a[R] - a[L + 1];
				L++;
			}
			else {
				ans -= k / cnt_L;
				break;
			}
		}
		else {
			if (k >= cnt_R * d_R) {
				k -= cnt_R * d_R;
				ans = a[R - 1] - a[L];
				R--;
			}
			else {
				ans -= k / cnt_R;
				break;
			}
		}
	}

	cout << ans;

	//cout << "\n"; system("pause");
	return 0;
}
/*

*/
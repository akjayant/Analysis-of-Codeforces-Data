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
		int n;
		string s;
		cin >> n >> s;
		bool b = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				b = true;
			}
		}
		if (!b) {
			cout << n << "\n";
		}
		else {
			int l = 0;
			int r = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '1') {
					break;
				}
				l++;
			}
			for (int i = n-1; i >= 0; i--) {
				if (s[i] == '1') {
					break;
				}
				r++;
			}
			cout << (2 * (n - min(l, r))) << "\n";
		}
	}

	//cout << "\n"; system("pause");
	return 0;
}
/*

*/
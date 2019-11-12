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

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s, t; cin >> s >> t;

		vector<int> dif;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				dif.push_back(i);
			}
		}

		if (dif.size() != 2) {
			cout << "No" << endl;
			continue;
		}

		if (s[dif[0]] == s[dif[1]] && t[dif[0]] == t[dif[1]]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	//cout << "\n"; system("pause");
	return 0;
}
/*

*/
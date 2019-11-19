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
		int n, m;
		cin >> n;

		long long cnt[4]{ 0,0,0,0 };

		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			if (p[i] % 2 == 0) {
				cnt[0]++;
			}
			else {
				cnt[1]++;
			}
		}
		cin >> m;
		vector<int> q(m);
		for (int i = 0; i < m; i++) {
			cin >> q[i];
			if (q[i] % 2 == 0) {
				cnt[2]++;
			}
			else {
				cnt[3]++;
			}
		}

		cout << cnt[0] * cnt[2] + cnt[1] * cnt[3] << "\n";
	}

	//cout << "\n"; system("pause");
	return 0;
}
/*

*/
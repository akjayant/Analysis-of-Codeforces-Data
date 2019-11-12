#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>
#include <numeric>
#include <functional>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.precision(7);
	cout.setf(ios::fixed);
	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		int ans = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int needa = i;
				int needb = 2 * i + j;
				int needc = 2 * j;

				if (a >= needa && b >= needb && c >= needc) {
					ans = max(ans, needa + needb + needc);
				}
			}
		}

		cout << ans << '\n';
	}
	return 0; 
}
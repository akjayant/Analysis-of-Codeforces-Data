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
	int n;
	cin >> n;

	vector<vector<int>>a(n, vector<int>(n, 0));
	int cur = 0;

	int v = 1;
	for (int j = 0; j + 1 < n; j++) {
		if (j % 2 == 0) {
			for (int i = 0; i < n; i++) {
				a[i][j] = v++;
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				a[i][j] = v++;
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		a[i][n - 1] = v++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		
		cout << '\n';
	}
	return 0; 
}
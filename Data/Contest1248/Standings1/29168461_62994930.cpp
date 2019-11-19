#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int const M = 1000000007;

vector<vector<int>> mmul(int n, vector<vector<int>> const& a, vector<vector<int>> const& b) {
	vector<vector<int>> result(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				(result[i][j] += int64_t(a[i][k]) * b[k][j] % M) %= M;
			}
		}
	}
	return result;
}

vector<vector<int>> mpow(int n, vector<vector<int>> a, int64_t power) {
	vector<vector<int>> result(n, vector<int>(n));
	for (int i = 0; i < n; ++i) { result[i][i] = 1; }
	while (power) {
		if (power & 1) {
			result = mmul(n, result, a);
		}
		a = mmul(n, a, a);
		power /= 2;
	}
	return result;
}

int msum(int n, vector<vector<int>> const& a) {
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			(result += a[i][j]) %= M;
		}
	}
	return result;
}

int A(int k) {
	vector<vector<int>> mat{{0, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 1, 0, 0}};
	if (k == 1) { return 2; }
	return msum(4, mpow(4, mat, k - 2));
}

int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 2 << endl;
		return 0;
	}
	cout << ((A(n) + A(m)) % M + M - 2) % M << endl;
}

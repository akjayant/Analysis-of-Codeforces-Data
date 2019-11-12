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

const int mod = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
	return a;
}

int mul(int a, int b) {
	return (int)((ll)a * b % mod);
}

int binpow(int a, int n) {
	int res = 1;

	while (n > 0) {
		if (n & 1) {
			res = mul(res, a);
		}

		a = mul(a, a);
		n >>= 1;
	}

	return res;
}

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
	int n, m;
	cin >> n >> m;
	int ans = binpow(2, m);
	ans = add(ans, -1);
	ans = binpow(ans, n);
	cout << ans;
	return 0; 
}
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define push_back pb
#define make_pair mp
#define MULTITEST int _test_no; cin >> _test_no; while (_test_no-- > 0)
#define MULTITEST_SCANF int _test_no; scanf("%d", &_test_no); while (_test_no-- > 0)
#define first ff
#define second ss
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector> 
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


void solve() {
	int n;
	cin >> n;
	vector<vi> a(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(n);
	}
	int cur = n * n;
	for (int j = 0; j < n; j++) {
		if (j % 2 == 0) {
			for (int i = 0; i < n; i++) {
				a[i][j] = cur--;
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				a[i][j] = cur--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#elif ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//MULTITEST_SCANF
	//MULTITEST
	solve();

	return 0;
}
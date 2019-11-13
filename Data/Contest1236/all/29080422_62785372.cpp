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
	int a, b, c;
	cin >> a >> b >> c;
	int mx = 0;
	int ta = a, tb = b, tc = c;
	for (int n = 0; n <= ta; n++) {
		a = ta;
		b = tb; 
		c = tc;

		int cur = min(n, min(a, b / 2));
		b -= 2 * cur;
		a -= cur;
		int t = min(b, c / 2);
		mx = max(mx, cur + t);
	}
	mx *= 3;
	cout << mx << endl;
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
	MULTITEST
		solve();

	return 0;
}
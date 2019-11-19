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

int main()
{
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n, m;
		cin >> n;
		vector<int> a(n);
		int a2[] = {0, 0}, b2[] = {0, 0};
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++a2[abs(a[i] % 2)];
		}
		cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
			++b2[abs(b[i] % 2)];
		}
		cout << int64_t(a2[0]) * b2[0] + int64_t(a2[1]) * b2[1] << endl;
	}
}

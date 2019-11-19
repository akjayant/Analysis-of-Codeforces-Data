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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int64_t S = accumulate(a.begin(), a.end(), 0LL);
	int64_t L = accumulate(a.begin(), a.begin() + n / 2, 0LL);
	cout << L * L + (S - L) * (S - L) << endl;
}

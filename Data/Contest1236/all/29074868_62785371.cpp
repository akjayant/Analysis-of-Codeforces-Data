#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <map>
#define int long long
#define double long double
using namespace std;


signed main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int res = 0;
		while (b > 0 && c > 1)
			b--, c -= 2, res += 3;
		while (a > 0 && b > 1)
			a--, b -= 2, res += 3;
		cout << res << endl;
	}
}
#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <sstream>

using namespace std;

#define ll long long
#define ld long double
const int inf = 1000000007;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	for (int t = 0; t < q; t++) {
		int n;
		cin >> n;
		vector <int> v(n);
		int max_cnt = 1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(begin(v), end(v), [](int a, int b) {return a > b; });
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (v[j] >= j - i + 1) {
					max_cnt = max(max_cnt, j - i + 1);
				}
			}
		}
		cout << max_cnt << endl;
	}
	return 0;
}





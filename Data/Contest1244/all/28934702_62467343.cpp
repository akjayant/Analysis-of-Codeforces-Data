#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <set>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;

int t;

int main () {
	cin >> t;

	while (t--) {
		int n, ans = 0;
		string s;
		cin >> n >> s;

		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				ans = max (ans, 2 * max (i + 1, n - i));
			}
			else ans = max (ans, max (i + 1, n - i));
		}

		cout << ans << endl;
	}
}
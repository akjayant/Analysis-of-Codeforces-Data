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
	for (int tt = 0; tt < q; tt++) {
		int n;
		cin >> n;

		string s, t;
		cin >> s >> t;

		vector <int> diff;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[i]) {
				diff.push_back(i);
			}
		}

		if (diff.size() > 2 || diff.size() == 1) {
			cout << "No\n";
		}
		else {
			if (diff.size() == 0)
				cout << "Yes\n";
			else {
				if (s[diff[0]] == s[diff[1]] && t[diff[0]] == t[diff[1]]) 
					cout << "Yes\n";
				else
					cout << "No\n";
				
			}
		}
	}
	return 0;
}





#include <bits/stdc++.h>
using namespace std;

int main (void) {
	int tests; cin >> tests;
	while (tests--) {
		int n; cin >> n;
		string s, t;
		cin >> s >> t;

		vector <int> diff;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i])
				diff.push_back(i);
		}

		if (diff.size() == 0) {
			cout << "Yes\n";
			continue ;
		}

		if (diff.size() != 2) {
			cout << "No\n";
			continue ;
		}

		vector <char> c;
		for (int i = 0; i < 2; ++i) {
			c.push_back(s[diff[i]]);
			c.push_back(t[diff[i]]);
		}

		if ((c[0] == c[2]) && (c[1] == c[3]))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
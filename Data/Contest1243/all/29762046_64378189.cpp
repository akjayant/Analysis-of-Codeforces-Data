#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int k;
	cin >> k;

	for (int l = 0; l < k; l++) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		set<char> sd, td;
		int ndiff = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				ndiff++;
				sd.insert(s[i]);
				td.insert(t[i]);
			}
		}
		if (ndiff == 2 && sd.size() == 1 && td.size() == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}

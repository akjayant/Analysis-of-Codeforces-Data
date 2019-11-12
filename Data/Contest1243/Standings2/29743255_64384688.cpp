#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<pair<int, int>> p;
 		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				p.emplace_back(s[i] - 'a', t[i] - 'a');
			}
		}
		if (p.size() == 0) {
			cout << "Yes" << endl;
		} else if (p.size() == 1) {
			cout << "No" << endl;
		} else if (p.size() == 2) {
			if (p[0] == p[1]) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
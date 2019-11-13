#include <iostream>
#include <string>
using namespace std;

string s, t;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n >> s >> t;
		int d = 0; pair<int, int> p(-1, -1);
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				if (p.first == -1) { p.first = i; }
				else { p.second = i; }
				d++;
			}
		}
		if (d == 0) { cout << "YES" << endl; }
		else if (d == 2 && s[p.first] == s[p.second] && t[p.first] == t[p.second]) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void Solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = n;
	int minpos = n + 1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			minpos = i;
			break;
		}
	}
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == '1') {
			int curpos = s.size() - 1 - i;
			minpos = curpos < minpos ? curpos : minpos;
			break;
		}
	}
	if (minpos != n + 1 && 2 * (n - minpos) > ans) {
		ans = 2 * (n - minpos);
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		Solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int ans[N], f[5], a[5];
int main() {
	string tt = "RPS";
	a[0] = 1, a[1] = 2, a[2] = 0;
	int q;
	cin >> q;
	while (q--) {
		int n;
		vector<int> r, p, s;
		cin >> n;
		cin >> f[0] >> f[1] >> f[2];
		string ss;
		cin >> ss;
		for (int i = 0; i < ss.size(); i++) {
			if (ss[i] == tt[0])
				r.push_back(i);
			if (ss[i] == tt[1])
				p.push_back(i);
			if (ss[i] == tt[2])
				s.push_back(i);
		}
		int sum = min((int) r.size(), f[a[0]]) + min((int) p.size(), f[a[1]]) + min((int) s.size(), f[a[2]]);
		if (sum >= (n + 1) / 2) {
			cout << "YES\n";
			for (int i = 0; i < r.size(); i++) {
				if (f[a[0]] > 0)
					ans[r[i]] = a[0] + 1, f[a[0]]--;
			}
			for (int i = 0; i < p.size(); i++) {
				if (f[a[1]] > 0)
					ans[p[i]] = a[1] + 1, f[a[1]]--;
			}
			for (int i = 0; i < s.size(); i++) 
				if (f[a[2]] > 0)
					ans[s[i]] = a[2] + 1, f[a[2]]--;
			for (int i = 0; i < n; i++) {
				if (ans[i] == 0) {
					for (int j = 0; j < 3; j++) {
						if (f[j] > 0) {
							ans[i] = j + 1;
							f[j]--;
							break;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				cout << tt[ans[i] - 1];
			}
			cout << endl;
		}
		else {
			cout << "NO\n";
		}
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}

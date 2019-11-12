#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const maxc = 130;

int fa[maxc], fb[maxc];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	
	int t;
	cin >> t;

	while (t--) {
		memset(fa, 0, sizeof(fa));
		memset(fb, 0, sizeof(fb));

		int n;
		cin >> n;

		string a, b;
		cin >> a >> b;

		for (int c : a) fa[c]++;
		for (int c : b) fb[c]++;

		bool ok = true;
		for (int i = 0; i < maxc and ok; i++) {
			if ((fa[i] + fb[i]) % 2 != 0) {
				cout << "No\n";
				ok = false;
			}
		}

		if (!ok) continue;

		vector<ii> res;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				fa[(int)a[i]]--;
				fb[(int)b[i]]--;
				continue;
			}

			auto troca = [&] (int x, int y) {
				fa[(int)a[x]]--;
				fb[(int)b[y]]--;
				fa[(int)b[y]]++;
				fb[(int)a[x]]++;
				swap(a[x], b[y]);
				res.emplace_back(x+1, y+1);
			};

			if (fa[(int)a[i]] >= 2) {
				for (int j = i+1; j < n; j++) {
					if (a[j] == a[i]) {
						troca(j, i);
						break;
					}
				}
			}
			else if (fb[(int)b[i]] >= 2) {
				for (int j = i+1; j < n; j++) {
					if (b[j] == b[i]) {
						troca(i, j);
						break;
					}
				}
			}
			else {
				for (int j = i+1; j < n; j++) {
					if (b[j] == a[i]) {
						troca(j, j);
						troca(j, i);
						break;
					}
				}
			}
			fa[(int)a[i]]--;
			fb[(int)b[i]]--;
		}

		cout << "Yes\n";
		cout << res.size() << "\n";
	
		for (auto i : res) cout << i.ff << " " << i.ss << "\n";
	}
}
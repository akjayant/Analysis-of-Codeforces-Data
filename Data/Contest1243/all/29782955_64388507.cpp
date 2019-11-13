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

		vector<ii> res;
		bool ok = true;
		for (int i = 0; i < maxc and ok and res.size() < 2; i++) {
			if ((fa[i] + fb[i]) % 2 != 0) {
				cout << "No\n";
				ok = false;
			}
		}

		if (!ok) continue;
		for (int i = 0; i < n and ok; i++) {
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
 	
 			if (fa[(int)a[i]] < 2 and fa[(int)a[i]] < 2) {
				ok = false;
				break;
			}

			bool ok2 = false;
			if (fa[(int)a[i]] >= 2) {
				for (int j = i+1; j < n; j++) {
					if (a[j] == a[i] and b[j] == b[i]) {
						troca(j, i);
						ok2 = true;
						break;
					}
				}
			}
			if (!ok2) {
				if (fa[(int)a[i]] >= 2) {
					for (int j = i+1; j < n; j++) {
						if (b[j] == b[i] and a[i] == a[j]) {
							troca(i, j);
							ok2 = true;
							break;
						}
					}
					
				}
			}
			if (!ok2) {
				ok = false;
				break;
			}

			fa[(int)a[i]]--;
			fb[(int)b[i]]--;
		}
		
		if (res.size() >= 2) ok = false;

		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
}
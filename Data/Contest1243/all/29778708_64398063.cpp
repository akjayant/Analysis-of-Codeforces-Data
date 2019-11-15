#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ii pair <int, int>
#define MP make_pair
#define F first
#define S second
#define L(x) ((x << 1) + 1)
#define R(x) ((x << 1) + 2)
#define mid(l, r) (l + r >> 1)
#define PB push_back
#define trace(x) cerr << #x << " = " << x << endl;
#define MAX 60

vector <ii> ans;
string s, t;


void move(int x, int y) {
	swap(s[x], t[y]);
	ans.PB(MP(x + 1, y + 1));
}

signed main() {
	fast_io;

	int k;

	cin >> k;

	while (k--) {
		int n;

		cin >> n;

		cin >> s >> t;

		map <char, int> C;

		C.clear();
		for (int i=0 ; i<n ; ++i) {
			C[s[i]]++;
			C[t[i]]++;
		}

		bool possible = true;
		for (auto el : C)
			if (el.S & 1)
				possible = false;

		if (!possible) {
			cout << "No\n";
			continue;
		}

		cout << "Yes\n";
		ans.clear();

		for (int i=0 ; i<n ; ++i) {
			if (s[i] == t[i])
				continue;
			for (int j=i+1 ; j<n ; ++j) {
				if (s[i] == s[j]) {
					move(j, i);
					break;
				}
				if (t[i] == t[j]) {
					move(i, j);
					break;
				}
				if (s[i] == t[j]) {
					move(j, j);
					move(j, i);
					break;
				}
				if (t[i] == s[j]) {
					move(j, j);
					move(i, j);
					break;
				}
			}
		}

		cout << ans.size() << endl;
		for (auto pr : ans)
			cout << pr.F << ' ' << pr.S << endl;

		assert(ans.size() <= (n << 1));
	}
}
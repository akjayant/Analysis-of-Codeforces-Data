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

signed main() {
	fast_io;

	int t;

	cin >> t;

	while (t--) {
		int n;
		string s, t;
		string s2, t2;

		cin >> n;

		cin >> s >> t;

		vector <int> pos;
		pos.clear();

		for (int i=0 ; i<n ; ++i) {
			if (s[i] != t[i])
				pos.PB(i);
		}

		bool possible = true;
		if (pos.size() > 2 or pos.size() == 1)
			possible = false;

		if (pos.size() == 2) {
			if (s[pos[0]] != s[pos[1]] or t[pos[0]] != t[pos[1]])
				possible = false;
		}

		cout << (possible ? "Yes\n" : "No\n");
	}
}
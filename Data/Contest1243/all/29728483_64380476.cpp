#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define emp emplace
typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k; cin >> k;

	while (k--) {
		int n; cin >> n;
		string s, t; cin >> s >> t;

		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				pos.eb(i);
			}
		}
		
		if (pos.size() != 2) {
			cout << "No" << endl;
		} else {
			if (s[pos[0]] == s[pos[1]] and t[pos[0]] == t[pos[1]]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}


	return 0;
}

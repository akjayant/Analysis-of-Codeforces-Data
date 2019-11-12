#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <pii, int> piii;

#define X first
#define Y second

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector <pii> vec;
		bool p = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				pii good = {-1, -1};
				for (int j = i + 1; j < n; j++)
					if (s[i] == s[j] || s[i] == t[j])
						good = {j, (s[i] == s[j])};
				if (good == pii(-1, -1)) {
					cout << "No\n";
					goto hell;
				}
				int j = good.X;
				if (good.Y == 1) {
					vec.push_back(pii(i, j));
					swap(t[i], s[j]);	
				} else {
					vec.push_back(pii(j, n - 1));
					swap(t[j], s[n - 1]);
					vec.push_back(pii(i, n - 1));
					swap(s[n - 1], t[i]);
				}
			}
		}
		if (s != t) {
			cout << "No";
			goto hell;
		}
		cout << "Yes\n";
		cout << vec.size() << endl;
		for (pii me: vec)
		   cout << me.Y + 1 << ' ' << me.X + 1 << endl;	
hell:;
	}
}

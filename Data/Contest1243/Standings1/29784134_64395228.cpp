#include <bits/stdc++.h>
using namespace std;

int k, n;
string s, t;
vector< pair<int, int> > v;

int main() {

	cin >> k;
	while (k--) {
		cin >> n;
		cin >> s;
		cin >> t;
		v.clear();
		
		int da = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				da = 0;
				for (int j = i+1; j < n; j++) {
					if (s[i] == s[j]) {
						swap(t[i], s[j]);
						v.push_back({j+1, i+1});
						da = 1;
						break;
					}
				}
				
				if (da == 0) {
					for (int j = i+1; j < n; j++) {
						if (s[i] == t[j]) {
							swap(s[j], t[j]);
							v.push_back({j+1, j+1});
							swap(s[j], t[i]);
							v.push_back({j+1, i+1});
							da = 1;
							break;
						}
					}
				}
				
				if (da == 0) {
					cout << "No\n";
					break;
				}
			}
		}
		if (da) {
			cout << "Yes\n";
			cout << v.size() << "\n";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i].first << " " << v[i].second << "\n";
			}
		}
	}


	return 0;
}

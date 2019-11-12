#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector <int> vec;
		map <char, int> cnt;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			if(s[i] != t[i])
				vec.push_back(i);
			cnt[s[i]]++;
			mx = max(mx, cnt[s[i]]);
		}
		if(vec.size() == 2) {
			int x = vec[0];
			int y = vec[1];
			if(s[x] == s[y] && t[x] == t[y])
				cout << "Yes";
			else 
				cout << "No";
		} else if (vec.size() == 0) {
			if (mx >= 2)
				cout << "Yes";
			else
				cout << "No";
		} else {
			cout << "No";
		}
		cout << endl;
	}
}

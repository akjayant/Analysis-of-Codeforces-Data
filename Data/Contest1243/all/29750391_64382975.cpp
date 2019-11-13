//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int q;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int> dif;
		for (int i = 0; i < n; i++)
			if (s[i] != t[i])
				dif.pb(i);
		if (dif.size() > 2 || dif.size() == 1) {
			cout << "No" << endl;
			continue;
		}
		if (dif.size() == 0) {
			int a[26] = {};
			for (auto i : s)
				a[i - 'a']++;
			bool flag = false;
			for (int i = 0; i < 26; i++)
				if (a[i] > 1)
					flag = true;
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (s[dif[0]] == s[dif[1]] && t[dif[0]] == t[dif[1]])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

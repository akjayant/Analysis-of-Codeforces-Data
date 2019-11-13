// In The Name Of GOD
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1024;
int q;
int n;
string s, t;

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cerr << "HELLO WORLD:)\n";
	cin >> q;
	while (q--) {
		cin >> n >> s >> t;
		vector<int> pos;
		pos.clear();
		for (int i = 0; i < n; i++)
			if (s[i] != t[i])
				pos.push_back(i);
		if (pos.size() > 2 || pos.size() == 1)
			cout << "No\n";
		else {
			if (pos.empty())
				cout << "Yes\n";
			else {
				swap(s[pos[0]], t[pos[1]]);
				if (s == t)
					cout << "Yes\n";
				else {
					swap(s[pos[0]], t[pos[1]]);
					swap(s[pos[1]], t[pos[0]]);
					if (s == t)
						cout << "Yes\n";
					else
						cout << "No\n";
				}
			}
		}
	}
	return false;
}
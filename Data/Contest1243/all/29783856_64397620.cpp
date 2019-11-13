#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 10000 + 10;

int n;
int k;
string s, f;
bool ansv[maxn];
vector <pair <int, int>> ansvar[maxn];
int slov[26];

signed main() {
	cin >> k;
	for (int c = 0; c < k; c++) {
		cin >> n;	
		cin >> s >> f;
		for (int i = 0; i < 26; i++) {
			slov[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			slov[s[i] - 'a'] += 1;
			slov[f[i] - 'a'] += 1;
		}
		bool check = 0;
		for (int i = 0; i < 26; i++) {
			if (slov[i] % 2 != 0) {
				check = 1;
			}
		}
		if (!check) {
			ansv[c] = 1;
			for (int i = 0; i < n - 1; i++) {
				bool ch = 0;
				for (int j = i; j < n; j++) {
					if (s[i] == f[j]) {
						ansvar[c].push_back(pair <int, int> (i + 1, j) );
						ansvar[c].push_back(pair <int, int> (i + 1, i) );
						swap(s[i + 1], f[j]);
						swap(s[i + 1], f[i]);

						ch  = 1;
						break;
					}
				}
				if (!ch) {
					for (int j = i + 1; j < n; j++) {
						if (s[i] == s[j]) {
							ansvar[c].push_back(pair <int, int> (j, i) );
							swap(s[j], f[i]);
							break;
						}
					}
				}
			}


		} else {
			ansv[c] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		if (ansv[i]) {
			cout << "Yes" << '\n';
			cout << ansvar[i].size() << '\n';
			for (auto d : ansvar[i]) {
				cout << d.first + 1 << ' ' << d.second + 1 << '\n';
			}

		} else {
			cout << "No";
			cout << '\n';
		}
		
	}
}

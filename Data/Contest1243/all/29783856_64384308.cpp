#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 10000 + 10;

int n;
int k;
string s, f;
bool ansv[11];

signed main() {
	cin >> k;
	for (int c = 0; c < k; c++) {
		cin >> n;
		cin >> s >> f;
		int counter = 0;
		int num[2];
		for (int i = 0; i < n; i++) {
			if (s[i] != f[i]) {
				counter++;
				if (counter > 2) {
					ansv[c] = 0;
					break;
				}
				num[counter - 1] = i;
			}
		}
		if (counter == 2) {
			if (s[num[1]] == s[num[0]] && f[num[0]] == f[num[1]]) {
				ansv[c] = 1;
			}
		}
		if (counter == 0) {
			ansv[c] = 1;
		}
		
	}
	for (int i = 0; i < k; i++) {
		if (ansv[i]) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << '\n';
	}
}

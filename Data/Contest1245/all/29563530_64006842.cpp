#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;

		int a, b, c;
		cin >> a >> b >> c;

		string str;
		cin >> str;

		int r = 0;
		int p = 0;
		int s = 0;
		for(char c : str) {
			if(c == 'R') {
				r++;
			}
			if(c == 'P') {
				p++;
			}
			if(c == 'S') {
				s++;
			}
		}

		queue<char> extra;
		for(int i = 0; i < a-s; i++) {
			extra.push('R');
		}
		for(int i = 0; i < b-r; i++) {
			extra.push('P');
		}
		for(int i = 0; i < c-p; i++) {
			extra.push('S');
		}

		int wins = min(a, s) + min(b, r) + min(c, p);
		if(wins >= n/2 + n%2) {
			cout << "YES" << endl;
			for(char ch : str) {
				if(ch == 'R') {
					if(b > 0) {
						cout << "P";
						b--;
					}
					else {
						cout << extra.front();
						extra.pop();
					}
				}
				if(ch == 'P') {
					if(c > 0) {
						cout << "S";
						c--;
					}
					else {
						cout << extra.front();
						extra.pop();
					}
				}
				if(ch == 'S') {
					if(a > 0) {
						cout << "R";
						a--;
					}
					else {
						cout << extra.front();
						extra.pop();
					}
				}
			}
			cout << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

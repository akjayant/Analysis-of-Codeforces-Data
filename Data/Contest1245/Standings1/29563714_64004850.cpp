#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
int nTest;
int n;
int a;
int b;
int c;
char s[MAX_N + 9];
char ans[MAX_N + 9];
int cntWin;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> nTest;
	for(int iTest = 1; iTest <= nTest; iTest++) {
		cin >> n >> a >> b >> c;
		for(int i = 1; i <= n; i++) {
			cin >> s[i];
		}
		cntWin = 0;
		fill(ans, ans + n + 1, 0);
		for(int i = 1; i <= n; i++) {
			if(a > 0 && s[i] == 'S') {
				ans[i] = 'R';
				a--;
				cntWin++;
			}
			else if(b > 0 && s[i] == 'R') {
				ans[i] = 'P';
				b--;
				cntWin++;
			}
			else if(c > 0 && s[i] == 'P') {
				ans[i] = 'S';
				c--;
				cntWin++;
			}
		}
		for(int  i = 1; i <= n; i++) {
			if(ans[i] == 0) {
				if(a > 0) {
					ans[i] = 'R';
					a--;
				}
				else if(b > 0) {
					ans[i] = 'P';
					b--;
				}
				else {
					ans[i] = 'S';
					c--;
				}
			}
		}
		if(cntWin < (n + 1) / 2) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for(int i = 1; i <= n; i++) {
				cout << ans[i];
			}
			cout << "\n";
		}
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
	int t, n, a, b, c;
	string bob;
	cin >> t;
	while(t--) {
		cin >> n;
		cin >> a >> b >> c;

		int toWin;
		if(n % 2 == 1) toWin = (n+1) / 2;
		else toWin = n/2;

		cin >> bob;
		int win = 0;
		vector<char> moves(n, 'N');
		for (int i = 0; i < n; ++i)
		{
			if(bob[i] == 'R' && b > 0) {
				moves[i] = 'P';
				b--; win++;
			} else if(bob[i] == 'P' && c > 0) {
				moves[i] = 'S';
				c--; win++;
			} else if(bob[i] == 'S' && a > 0) {
				moves[i] = 'R';
				a--; win++;
			}
		}
		if(win >= toWin) {
			cout << "YES" << endl;
			for (int i = 0; i < n; ++i)
			{
				if(moves[i] != 'N') {
					cout << moves[i];
				} else {
					if(a-- > 0) cout << 'R';
					else if(b-- > 0) cout << 'P';
					else if(c-- > 0) cout << 'S';
				}
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
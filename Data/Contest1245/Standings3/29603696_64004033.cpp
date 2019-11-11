#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int R, P, S;
		cin >> R >> P >> S;
		string str;
		cin >> str;
		int bR = 0, bP = 0, bS = 0;
		for (auto it : str) {
			if (it == 'R') bR++;
			if (it == 'P') bP++;
			if (it == 'S') bS++;
		}
		int k = min(R, bS) + min(P, bR) + min(S, bP);
		if (2 * k >= n) {
			cout << "YES\n";
			char ans[105];
			for (int i = 0; i < n; i++) {
				if (str[i] == 'R' && P > 0) { ans[i] = 'P', P--; }
				else if (str[i] == 'P' && S > 0) { ans[i] = 'S', S--; }
				else if (str[i] == 'S' && R > 0) { ans[i] = 'R', R--; }
				else ans[i] = 't';
			}
			vector<char> can; int c = 0;
			for (int i = 0; i < R; i++) can.push_back('R');
			for (int i = 0; i < P; i++) can.push_back('P');
			for (int i = 0; i < S; i++) can.push_back('S');
			for (int i = 0; i < n; i++) {
				if (ans[i] != 't') {
					cout << ans[i];
				}
				else cout << can[c++];
			}
			cout << endl;
		}
		else cout << "NO\n";

	}
}
/*
2 5
2 3 0
SSSSS
*/
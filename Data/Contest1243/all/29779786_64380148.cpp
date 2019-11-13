#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		string S, T;
		int n; cin >> n;
		cin >> S;
		cin >> T;
		int idx1 = -1, idx2 = -1;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (S[i] != T[i]) {
				cnt++;
				if (idx1 == -1) {
					idx1 = i;
				}
				else if (idx2 == -1) {
					idx2 = i;
				}
			}
		}

		if (cnt != 2) {
			cout << "No\n";
		}
		else {
			if (S[idx1] == S[idx2] && T[idx1] == T[idx2]) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
	}
	return 0;
}
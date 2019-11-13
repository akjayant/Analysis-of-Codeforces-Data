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

int cnt1[30], cnt2[30];

int main() {
	int tc; cin >> tc;
	while (tc--) {
		string S, T;
		int n; cin >> n;
		cin >> S;
		cin >> T;
		reset(cnt1, 0); reset(cnt2, 0);
		for (int i = 0; i < n; i++) {
			cnt1[S[i] - 'a']++;
			cnt2[T[i] - 'a']++;
		}
		bool ok = true;
		for (int i = 0; i < 26; i++) {
			int tot = cnt1[i] + cnt2[i];
			if (tot & 1) ok = false;
		}

		if (!ok) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
			vii ans;
			for (int i = 0; i < n; i++) {
				if (S[i] == T[i]) continue;
				bool fix = false;
				for (int j = i+1; j < n; j++) {
					if (S[i] == S[j]) {
						ans.push_back({j+1, i+1});
						swap(S[j], T[i]);
						fix = true;
						break;
					}
				}

				if (fix) continue;

				for (int j = i+1; j < n; j++) {
					if (S[i] == T[j]) {
						ans.push_back({j+1, j+1});
						ans.push_back({j+1, i+1});
						swap(S[j], T[j]);
						swap(S[j], T[i]);
						break;
					}
				}
			}

			cout << sz(ans) << "\n";
			for (ii p : ans) {
				cout << p.fi << " " << p.se << "\n";
			}
		}
	}
	return 0;
}
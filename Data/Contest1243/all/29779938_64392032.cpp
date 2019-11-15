#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>


using namespace std;

#define _GLIBCXX_DEBUG

#define FOR(i, L, R) for (int i = (L); i < (R); i++)
#define FR(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair <int, int> pii;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int k; cin >> k;
	vector <pii> a;

	char S[50], T[50];
	int alph[26];

	FR(Q, k) {
		
		int m; cin >> m;
		
		FR(i, m) cin >> S[i];
		FR(i, m) cin >> T[i];
		FR(i, 26) alph[i] = 0;

		FR(i, m) alph[S[i] - 'a']++;
		FR(i, m) alph[T[i] - 'a']++;

		bool ans = 1;
		FR(i, 26) if (alph[i] % 2 == 1) ans = 0;
		
		a.clear();

		FR(i, m - 1) {
			
			if (S[i] != T[i]) {

				int j = -1;
				FOR(q, i + 1, m) if (S[q] == S[i]) j = q;

				if (j != -1) {

					a.push_back(make_pair(j + 1, i + 1));
					swap(S[j], T[i]);
				
				}
				else {

					FOR(q, i, m) if (T[q] == S[i]) j = q;
					
					a.push_back(make_pair(i + 2, j + 1));
					a.push_back(make_pair(i + 2, i + 1));

					swap(S[i + 1], T[j]);
					swap(S[i + 1], T[i]);

				}
			}

		}

		if (ans) {
			cout << "Yes\n";

			cout << a.size() << '\n';
			for (auto x : a) cout << x.first << ' ' << x.second << '\n';
		}
		else cout << "No\n";

	}

	return 0;
}

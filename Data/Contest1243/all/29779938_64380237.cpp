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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n; cin >> n;
	FR(T, n) {
		
		int m; cin >> m;
		string s, t; cin >> s >> t;
		bool ans = 1;

		int ch = 0; int j;

		FR(i, m) {
			
			if (s[i] != t[i]) {
				
				if (ch > 1) ans = 0;

				if (ch == 0) j = i;

				if (ch == 1) {
					
					if (!(s[i] == s[j] && t[j] == t[i])) ans = 0;

				}

				ch++;

			}

		}
		if (ch <= 1) ans = 0;

		if (ans) cout << "Yes\n";
		else cout << "No\n";

	}

	return 0;
}

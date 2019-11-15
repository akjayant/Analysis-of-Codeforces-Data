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


	int t; cin >> t;
	FR(T, t) {
	
		int n; cin >> n; 
		vector <int> a(n);

		FR(i, n) cin >> a[i];
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());

		int ans = 0;
		FR(j, n) {
			
			if (a[j] > ans)
				ans++;
			else break;

		}

		cout << ans << '\n';
	}

	return 0;
}

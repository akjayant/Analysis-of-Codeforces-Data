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

	ll n; cin >> n; ll N = n;

	/*ll dlt = 1;

	ll i = 2;
	bool ans = 1;
	while (i * i <= n) {
		
		if (n % i == 0 && (dlt == 1 || dlt == i))
			dlt = i, n /= i;
		else if (n % i == 0) ans = 0, i++;
		else i++;

	}

	if (n != 1) {
		
		if (dlt != 1 && n != dlt && n != 1) ans = 0;

	}

	if (!ans) cout << 1;
	else cout << N / dlt;*/

	ll dlt = -1;
	ll i = 2;

	while (i * i <= n) {
	
		if (n % i == 0) {
			
			dlt = i;
			break;

		}

		i++;

	}

	if (dlt == -1) cout << N;
	else {
		while (n % dlt == 0) n /= dlt;

		if (n != 1) cout << 1;
		else cout << dlt;
	}

	return 0;
}

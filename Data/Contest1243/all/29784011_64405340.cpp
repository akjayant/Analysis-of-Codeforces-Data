#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int SQRT = 1e6;
int n;
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	//If n is power of a prime or a prime itself print the prime. Else print 1.
	int cntSmall = 0;
	fw (i, 2, SQRT + 1) if (n % i == 0) cntSmall++;
	if (cntSmall == 0) {
		cout << n;
		return 0;
	}
	if (cntSmall > 0) {
		int smallestDivi = -1;
		fw (i, 2, SQRT + 1) if (n % i == 0) {
			smallestDivi = i;
			break;
		}
		while (n % smallestDivi == 0) n /= smallestDivi;
		if (n == 1) cout << smallestDivi;
		else cout << 1;
		return 0;
	}
	return 0;
}
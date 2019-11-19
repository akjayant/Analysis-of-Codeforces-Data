#include <bits/stdc++.h>
//#include <ext/numeric>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define popcount(n) __builtin_popcount(n)
#define popcountll(n) __builtin_popcountll(n)
#define long long long

using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI = acos(-1.0), EPS = 1e-9;

int main() {

	long n;
	cin >> n;
	long ans = n;
	for (long i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ans = __gcd(ans, i);
			ans = __gcd(ans, n / i);
		}
	}

	cout << ans << '\n';


	return 0;
}

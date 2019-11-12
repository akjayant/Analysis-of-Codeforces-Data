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

	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int &x : arr)
			cin >> x;
		sort(arr.rbegin(), arr.rend());
		int ans = 0;
		int mn = n;
		for (int i = 0; i < n; ++i) {
			mn = min(arr[i], mn);
			ans = max(ans, min(mn, i + 1));
		}
		cout << ans << '\n';
	}

	return 0;
}

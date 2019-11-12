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
		string s, t;
		cin >> s >> t;
		int cnt = 0;
		int idx1, idx2;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				++cnt;
				if (cnt == 1)
					idx1 = i;
				else
					idx2 = i;
			}
		}

		if (cnt != 0 && cnt != 2) {
			cout << "No\n";
			continue;
		}

		if (cnt == 0 || (s[idx1] == s[idx2] && t[idx1] == t[idx2]))
			cout << "Yes\n";
		else
			cout << "No\n";
	}


	return 0;
}

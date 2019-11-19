#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	for (; t > 0; t--) {
		int n;
		string s;
		cin >> n >> s;
		
		size_t lst1 = s.rfind('1');
		size_t fst1 = s.find('1');
		
		if (fst1 == string::npos) {
			cout << n << "\n";
		} else {
			cout << max((lst1 + 1) * 2, (n - fst1) * 2) << "\n";
		}
	}
}

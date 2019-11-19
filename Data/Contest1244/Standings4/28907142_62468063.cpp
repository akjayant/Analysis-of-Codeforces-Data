#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define ll long long 
#define fi first
#define se second

//CHECK FOR N = 1 OR OTHER DUMB TESTS 

using namespace std;

int t, ok[100100], n;
char c;

int main() {
	//ifstream cin("tst.in");
	//ofstream out("tst.out");
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			ok[i] = 0;
		
		int flag = 0;
		
		int fst, lst;
		fst = 2e9;
		lst = -1;
		
		for (int i = 1; i <= n; i++) {
			cin >> c;
			if (c == '1') {
				ok[i] = 1;
				flag = 1;
				fst = min(fst, i);
				lst = max(lst, i);
			}
		}
		
		if (flag == 0) {
			cout << n << '\n';
			continue;
		}
		
		cout << max({n, 2 * lst, 2 * (n - fst + 1)}) << '\n';
	}	
	return 0;
}
#include<algorithm>
#include <cstdio>
#include <string>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
#include<map>
#include<iostream>
#include<functional>
#include<cstring>
#include<stack>

using namespace std;
void fastio() {
	iostream::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
char a[1111];
int main() {
	fastio();
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		cin >> a+1;
		int dap = n;
		for (int i = 1; i <= n; i++) {
			if (a[i] == '1') {
				int dd = max(i, n + 1 - i) * 2;
				dap = max(dap, dd);
			}
		}
		cout << dap << '\n';
	}
	
}
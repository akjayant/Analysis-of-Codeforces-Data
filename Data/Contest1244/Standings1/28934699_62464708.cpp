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
int main() {
	fastio();
	int T; cin >> T;
	while (T--) {
		int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
		int yes = 0;
		for (int i = 0; i <= k; i++) {
			if (c*i >= a && d*(k - i) >= b) {
				yes = 1;
				cout << i << ' ' << k - i << '\n';
				break;
			}
		}
		if (!yes)cout << -1 << '\n';
	}
	
}
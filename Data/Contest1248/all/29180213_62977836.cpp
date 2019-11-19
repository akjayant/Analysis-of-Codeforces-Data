#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define Push push_back
typedef long long lli;
typedef pair<lli, lli> pll;
typedef vector<lli> vcL;
typedef vector<pll> vPL;

void solve() {
	lli n, m, tmp, ans = 0;
	cin >> n;
	
	lli odd = 0, even = 0;
	while (n--) {
		cin >> tmp;
		(tmp % 2 == 0) ? ++even : ++odd;
	}
	
	cin >> m;
	while (m--) {
		cin >> tmp;
		ans += (tmp % 2 == 0) ? even : odd;
	}
	
	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	
	while (t--) solve();
	
	return 0;
}
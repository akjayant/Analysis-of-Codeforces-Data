#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define Push push_back
typedef long long lli;
typedef pair<lli, lli> pll;
typedef vector<lli> vcL;
typedef vector<pll> vPL;

int main() {
	lli n;
	cin >> n;
	
	vcL num(n);
	for (auto &x : num) cin >> x;
	
	sort(num.begin(), num.end());
	
	lli vertical = 0, horizontal = 0;
	for (int i = 0; i < n; ++i) {
		if (i < n / 2) vertical += num[i];
		else horizontal += num[i];
	}
	
	cout << vertical * vertical + horizontal * horizontal << "\n";
	
	return 0;
}
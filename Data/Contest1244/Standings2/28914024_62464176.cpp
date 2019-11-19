#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int a, b, c, d, e; 
		cin >> a >> b >> c >> d >> e;
		int f = (a + c - 1) / c, g = (b + d - 1) / d;
		if(f + g > e) puts("-1");
		else cout << f << " " << g << endl;
	}
	return 0;
}
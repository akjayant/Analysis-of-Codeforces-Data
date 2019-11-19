#include  <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	int q; cin >> q;
	while(q--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = (a-1)/c + 1;
		int y = (b-1)/d + 1;
		if(x + y <= k) {
			cout << x << ' ' << y << endl;
		} else {
			cout << "-1" << endl;
		}
	}
	return 0;
}
#include<iostream>
using namespace std;

int T, a, b, c, d,e,x,y;

int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d >> e;
		x = a / c;
		if (a%c) x++;
		y = b / d;
		if (b%d)y++;
		if (x + y <= e) cout << x << ' ' << y << '\n';
		else cout << "-1\n";
	}
}
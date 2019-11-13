#include <bits/stdc++.h>
#define read_int(x) int x; cin >> x
#define FOR(x,a,b) for(int x = a; x < b; x++)

using namespace std;

int main() {
	read_int(t);
	FOR(i, 0, t) {
		read_int(a);
		read_int(b);
		read_int(c);
		//x + (2x + y) + 2y
		int y = min(c / 2, b);
		int x = min(a, (b - y) / 2);
		printf("%d\n", (x + y) * 3);
	}

	return 0;
}
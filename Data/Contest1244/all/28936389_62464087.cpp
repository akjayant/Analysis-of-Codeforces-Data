#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
// int lowbit(int x) {
// 	return x & (-x);
// }

// void add(int i, int x, int a) {
// 	while (x <= len) {
// 		tree[i][x] += a;
// 		x += lowbit(x);
// 	}
// }

// int ask(int i, int x) {
// 	int res = 0;
// 	while (x) {
// 		res += tree[i][x];
// 		x -= lowbit(x);
// 	}
// 	return res;
// }



int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int a, b, c, d, k;
	while (t--) {
		cin >> a >> b >> c >> d >> k;
		int na = a / c, nb = b / d;
		if (na * c != a)na++;
		if (nb * d != b)nb++;
		if (na + nb > k) cout << -1 << endl;
		else {
			cout << na << " " << nb << endl;
		}
	}
	return 0;
}
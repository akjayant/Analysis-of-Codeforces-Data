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

char str[1005];

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int len; cin >> len;
		cin >> (str + 1);
		int l = 0, r = 0;
		for (int i = 1; i <= len; i++)
			if (str[i] == '1') {
				if (l == 0) l = i;
				r = i;
			}
		if (l == 0) cout << len << endl;
		else cout << max(len, len * 2 - 2 * min(l - 1, len - r)) << endl;
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
#define ull unsigned long long
int T, n;
char room[1005];
int main() {
#ifdef _DEBUG
	freopen("stdin.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> room;
		int l = -1, r = n;
		for (int i = 0; i < n; ++i)
			if (room[i] == '1') {
				l = i;
				break;
			}
		if (l == -1) {
			cout << n << endl;
			continue;
		}
		for (int i = n - 1; i >= l; --i)
			if (room[i] == '1') {
				r = i;
				break;
			}
		int a1 = 2 * (r + 1);
		int a2 = 2 * (n - l);
		int a3 = r - l + 1 + max(l + 1, n - r) + max(r - l, min(l + 1, n - r));
		cout << max(a1, max(a2, l == r ? 0 : a3)) << endl;
	}
}
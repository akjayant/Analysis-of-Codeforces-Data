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
int T, a, b, c, d, k;
int main() {
#ifdef _DEBUG
	freopen("stdin.txt", "r", stdin);
#endif
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d >> k;
		int x = a / c + (a % c != 0), y = b / d + (b % d != 0);
		if (x + y > k)
			cout << -1 << endl;
		else cout << x << ' ' << y << endl;
	}
}
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <iomanip>
#include <functional>
#include <ctime>
#include <random>

#pragma warning(disable:4996);
#define mem(sx,sy) memset(sx,sy,sizeof(sx))
#define pa pair<ll, int>
#define pll pair<ll, ll>
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, ((l + r) >> 1), lson
#define Rson ((l + r) >> 1) + 1, r, rson

typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const int MAXN = 1e5 + 7;

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		int t1 = min(b, c / 2);

		int t2 = min(a, (b - t1) / 2);

		cout << (t1 + t2) * 3 << endl;

	}
}
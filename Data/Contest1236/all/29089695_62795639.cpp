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
typedef long long ll;

int g[500][500];
int main() {
	int n;
	cin >> n;
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		if (i & 1)
			for (int j = 1; j <= n; j++) g[i][j] = cur++;
		else
			for (int j = n; j >= 1; j--) g[i][j] = cur++;
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}
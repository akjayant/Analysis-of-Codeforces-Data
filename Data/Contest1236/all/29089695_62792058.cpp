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

ll ksm(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % MOD;
		b /= 2;
		a = a * a % MOD;
	}
	return ret;
}
int main() {
	int n, m;
	cin >> n >> m;
	ll t = (ksm(2, m) - 1 + MOD) % MOD;
	cout << ksm(t, n) << endl;
}
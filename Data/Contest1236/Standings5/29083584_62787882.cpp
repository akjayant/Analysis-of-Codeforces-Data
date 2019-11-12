#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int, int>
using namespace std;

const int maxn = 1e7 + 5;
const int N = 1e6 + 5;
const int mod = 1000;
const double PI = acos(-1.0);
const long long inf = 0x3f3f3f3f;

int a, b, c;

int main() {
	int t;  cin >> t;
	while(t--) {
		int ans = 0;
		cin >> a >> b >> c;
		ans += min(b, c/2) * 3;
		b -= min(b, c/2);
		ans += min(a, b/2) * 3;
		cout << ans << endl;
	}
	return 0;
}
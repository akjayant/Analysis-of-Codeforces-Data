//#define _CLIBCXX_DEBAG
//#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdint>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <limits>
#include <cstdio>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <ctime>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pi acos(-1.0)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

constexpr auto inf = 1e9;
constexpr auto eps = 1e-9;

typedef double db;
typedef long long ll;

void solve() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, ans=0;
		cin >> a >> b >> c;
		ans+=min(b, c / 2) * 3;
		b -= min(b, c / 2);
		c -= min(b, c / 2) * 2;
		ans += min(a, b / 2) * 3;
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
/*

*/
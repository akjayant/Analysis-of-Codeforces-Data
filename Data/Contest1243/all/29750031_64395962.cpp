#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <functional>
#include <algorithm>
#include <utility>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <complex>
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long double C;
typedef complex<C> P;

#define X real()
#define Y imag()
#define Size(X) (int)X.size()
#define int long long
#define ui unsigned int
#define mp make_pair
#define timer fghge
#define y1 yjyjyju
#define all(X) (X).begin(), (X).end()
#define endl '\n'

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n; cin >> n;
	int ans = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans = i;
			break;
		}
	}
	int cntr = ans;
	if (ans == n)
		cout << ans;
	else {
		vector<bool> flag(ans);
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				int fir = i, sec = n / i;
				for (int j = 0; j < n; j += fir) {
					if (flag[j % ans] == 0 && j > 0)
						cntr--;
					flag[j % ans] = 1;
					if (j % ans == 0 && j > 0)
						break;
				}
				for (int j = 0; j < n; j += sec) {
					if (flag[j % ans] == 0 && j > 0)
						cntr--;
					flag[j % ans] = 1;
					if (j % ans == 0 && j > 0)
						break;
				}
			}
		}
		cout << cntr;
	}
	return 0;
}
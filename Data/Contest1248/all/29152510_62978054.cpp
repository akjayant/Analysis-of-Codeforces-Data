#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define test cerr << '!' << endl;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main0 ();
int main () {
	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\98497\\Desktop\\code\\file.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	// clock_t start,end;
	// start = clock();
	main0();
	// end = clock();
	// cout << (end - start) << endl;
	#ifndef ONLINE_JUDGE
		fclose(stdin);
	#endif
	return 0;
}

const int INF = 0x3f3f3f3f;
const int N = 1e5;
const int M = 1e5;
const int mod = 1e9 + 7;

int main0 () {
	int T;
	cin >> T;
	while (T--) {
		ll a1, a2, b1, b2;
		a1 = a2 = b1 = b2 = 0;
		int n, m, t;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> t;
			if (t & 1) a1++;
			else a2++;
		}
		cin >> m;
		for (int i = 1;i <= m;i++) {
			cin >> t;
			if (t & 1) b1++;
			else b2++;
		}
		
		cout << a1 * b1 + a2 * b2 << endl;
	}
}

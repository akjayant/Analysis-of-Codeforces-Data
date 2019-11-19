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
const int N = 1e5 + 5;
const int M = 1e5;
const int mod = 1e9 + 7;

ll fib[N];

int main0 () {
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3;i < N;i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= mod;
	}
	
	ll n, m;
	cin >> n >> m;
	ll ans = 2 * (fib[n] + fib[m] - 1);
	ans %= mod;
	cout << ans << endl;
}

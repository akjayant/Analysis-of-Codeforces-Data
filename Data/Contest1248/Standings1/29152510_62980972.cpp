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

int a[N];

bool cmp (int a, int b) {
	return a > b;
}

int main0 () {
	ll n, sum = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	
	ll t = 0;
	for (int i = 1;i <= (n + 1) / 2;i++) {
		t += a[i];
	}
	
	cout << t * t + (sum - t) * (sum - t) << endl;
}

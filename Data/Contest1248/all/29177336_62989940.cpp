#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

typedef long long ll;
#define MOD 1000000007

ll getFib(int n) {
	ll a = 0;
	ll b = 1;
	for (int i = 0; i < n; ++i) {
		int c = (a + b) % MOD;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#else
//	freopen("input.txt","r",stdin);
//	freopen("output.txt", "w",stdout);
#endif
	int n, m;
	cin >> n >> m;
	cout << (getFib(n) + getFib(m) - 1) * 2 % MOD << endl;
	return 0;
}
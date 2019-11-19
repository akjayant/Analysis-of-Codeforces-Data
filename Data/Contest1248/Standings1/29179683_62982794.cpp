#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <set>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;
 
ll t, n, m, a[1000000], sum;

int main () {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
		sum += a[i];
	}

	sort (a, a + n);

	ll c = 0;

	for (int i = 0; i < n / 2; i++) {
		c += a[i];
	}

	cout << c * c + (sum - c) * (sum - c);
}
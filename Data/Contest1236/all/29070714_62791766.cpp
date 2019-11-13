// " --- IN THE NAME OF ALLAH --- " // ;)
// ------------sphr_agz------------ // ;)

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <list>
#include <stack>
#include <bitset>
#include <ctime>
using namespace std;

typedef long double ld;
typedef long long int lli;
#define pb(x) push_back(x)
#define recout(x) return cout << (x), 0
#define fr first
#define sc second
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define stp(x) cout << setprecision(x) << fixed
#define mk make_pair
const lli N = 1e6, N2 = 5e3, delta = 46639, mod = 1e9 + 7, oo = 1e16;
const ld PI = 3.141592653589793;

lli power (lli k, lli n) {
	if (n == 0)
		return 1;
	if (n % 2) {
		lli x = power (k, n / 2);
		x *= x;
		x %= mod;
		x *= k;
		x %= mod;
		return x;
	}
	lli x = power (k, n / 2);
	x *= x;
	x %= mod;
	return x;
}

int main () {
	lli n, m;
	cin >> n >> m;
	cout << power (power (2, m) - 1, n);
}

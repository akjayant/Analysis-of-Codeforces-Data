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

vector <lli> v[N];

int main () {
	lli n, cnt = 1;
	cin >> n;
	for (lli i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (lli j = 0; j < n; j++) {
				v[j].pb(cnt);
				cnt++;
			}
		}
		else {
			for (lli j = n - 1; j >= 0; j--) {
				v[j].pb(cnt);
				cnt++;
			}
		}
	}
	for (lli i = 0; i < n; i++) {
		for (lli j = 0; j < n; j++)
			cout << v[i][j] << ' ';
		cout << "\n";
	}
}

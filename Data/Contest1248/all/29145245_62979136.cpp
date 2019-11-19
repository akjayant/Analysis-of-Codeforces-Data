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
#define fr first
#define sc second
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define stp(x) cout << setprecision(x) << fixed
#define mk make_pair
const lli N = 1e6, N2 = 5e3, delta = 46639, mod = 1e9 + 7, oo = 1e16;
const ld PI = 3.141592653589793;

lli p[N], q[N];

int main(){
	lli t;
	cin >> t;
	while (t--) {
		lli n, m, cnt1e = 0, cnt2e = 0, cnt1o = 0, cnt2o = 0;
		cin >> n;
		for (lli i = 0; i < n; i++) {
			cin >> p[i];
			if (p[i] % 2 == 0)
				cnt1e++;
			else
				cnt1o++;
		}
		cin >> m;
		for (lli i = 0; i < m; i++) {
			cin >> q[i];
			if (q[i] % 2 == 0)
				cnt2e++;
			else
				cnt2o++;
		}
		cout << cnt1e * cnt2e + cnt1o * cnt2o << "\n";
	}
}

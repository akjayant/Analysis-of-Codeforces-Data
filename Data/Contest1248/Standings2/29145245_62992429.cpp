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

lli f[N];

int main(){
	lli n, m;
	cin >> n >> m;
	f[1] = 2;
	f[2] = 4;
	for (lli i = 3; i < 1e6; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= mod;
	}
	cout << (f[n] + f[m] - 2) % mod;
}

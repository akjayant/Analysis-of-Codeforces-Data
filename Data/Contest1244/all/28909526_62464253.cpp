//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math") 
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native") 
// #pragma GCC target("avx,avx2")

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define ll long long

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9;
const ld PI = 3.14159265358979323846264;
const ld leng = 1e10;
const ld bigConstant = 1e6;
const ll maxn = 1e8 + 1;
const ll mod = 1e9 + 7;
const ll maxv = 360;
const int bsz = 500;
const int maxlog = 32;



int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		bool u = false;
		for (int x = 0; x <= k; x++) {
			if (x * c >= a && (k - x) * d >= b) {
				u = true;
				cout << x << " " << k - x << "\n";
				break;
			}
		}
		if (!u) cout << -1 << "\n";
	}
	return 0;
}
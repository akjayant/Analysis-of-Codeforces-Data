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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int curmax = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				curmax = max(curmax, i + 1);
				curmax = max(curmax, int(s.size()) - i);
			}
		}
		if (curmax == 0)
			cout << s.size() << "\n";
		else
			cout << 2 * curmax << "\n";
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <deque>
#include <random>
#include <chrono>
#include <ctime>
#include <climits>
#include <stack>
#include <array>
#include <iomanip>
#include <complex>
#include <bitset>
#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) a.begin(), a.end()
#define len(a) (int)a.size()
#define pb push_back
#define eb emplace_back
#define em emplace
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam

void useiostream() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(8);
}

void drop(char const* bu) {
	printf("%s", bu);
	exit(0);
}


ull gcd(ull a, ull b) {
	return b == 0 ? a : gcd(b, a % b);
}



ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ld const pi = acos(-1.0L);
ld const eps = 0.0001L;

template<typename T, typename TT> bool mi(T& a, TT b) { return a > b ? (a = b, true) : false; }
template<typename T, typename TT> bool ma(T& a, TT b) { return a < b ? (a = b, true) : false; }

mt19937 ran(996);

int const mod = 1000000007;

ull bm(ull a, ull p, ull mod) {
	ull re = 0;
	while (p) {
		if (p & 1)re = (re + a) % mod;
		p >>= 1;
		a = (a + a) % mod;
	}
	return re;
}

ull bp(ull a, ull p, ull mod) {
	ull re = 1;
	while (p) {
		if (p & 1)re = bm(re, a, mod);
		p >>= 1;
		a = bm(a, a, mod);
	}
	return re;
}






int main() {
	useiostream();
#ifdef _DEBUG
	(void)freopen("input.txt", "r", stdin);
	(void)freopen("output.txt", "w", stdout);
#else
	//(void)freopen("bisector.in", "r", stdin);
	//(void)freopen("bisector.out", "w", stdout);
#endif

	int a;
	cin >> a;
	while (a--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				for (int j = i + 1; j < n; j++) {
					if (a[i] == a[j] && b[i] == b[j]) {
						swap(b[i], a[j]);
						break;
					}
					
				}
				if (a[i] == b[i])break;
				for (int j = i + 1; j < n; j++) {
					if (b[j] == b[i] && a[i] == a[j]) {
						swap(a[i], b[j]);
						break;
					}
				}
				break;
			}
		}
		if (a == b)cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
//#define NDEBUG
#define REL
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <climits>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define nn "\n"
#define pp " "

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

template <typename T>
bool uax(T &a, const T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T>
bool uin(T &a, const T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
	in >> p.first >> p.second;
	return in;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p) {
	out << p.first << ' ' << p.second;
	return out;
}

mt19937 rnd(1928);


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("linkcut.in", "r", stdin);
	//freopen("linkcut.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	int t;
	cin >> t;
	int n, a, b, c;
	string s, r;
	while (t--) {
		cin >> n;
		cin >> a >> b >> c;
		cin >> s;
		r.assign(n, char(0));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R' && b > 0) {
				r[i] = 'P';
				b--;
				ans++;
			}
			if (s[i] == 'P' && c > 0) {
				r[i] = 'S';
				c--;
				ans++;
			}
			if (s[i] == 'S' && a > 0) {
				r[i] = 'R';
				a--;
				ans++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (r[i] == char(0)) {
				if (a > 0) {
					a--;
					r[i] = 'R';
					continue;
				}
				if (b > 0) {
					b--;
					r[i] = 'P';
					continue;
				}
				if (c > 0) {
					c--;
					r[i] = 'S';
					continue;
				}
			}
		}
		if (ans >= (n + 1) / 2) {
			cout << "YES" << nn;
			cout << r << nn;
		}
		else {
			cout << "NO" << nn;
		}
	}
}
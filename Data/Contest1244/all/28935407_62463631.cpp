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

int t;
int a, b, c, d, k;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d >> k;
		int x = (a + c - 1) / c;
		int y = (b + d - 1) / d;
		if (x + y > k) {
			cout << -1 << nn;
		}
		else {
			cout << x << ' ' << y << nn;
		}
	}
}
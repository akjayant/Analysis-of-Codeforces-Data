#pragma comment(linker, "/STACK:134217728")
#pragma GCC optimize("fast-maths")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
using namespace std;

#define forx(_name,_from, to, value) for (int name = from; name < to; name += value)
#define rforx(_name, from, to, value) for (int name = from; name > to; name -= _value)
#define all(_STL_NAME) _STL_NAME.begin(), _STL_NAME.end()
#define rall(_STL_NAME) _STL_NAME.rbegin(), _STL_NAME.rend()
#define mp(_FIRST,_SECOND) make_pair(_FIRST,_SECOND)

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
const ld eps = 1e-12;
mt19937 rndm;

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20); cout.setf(ios::fixed);
	string FILENAME = "navalny";
	rndm.seed(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen((FILENAME + ".in").c_str(), "rt", stdin);
	//freopen((FILENAME + ".out").c_str(), "wt", stdout);
#endif
}

inline int FastIn(FILE* streamin = stdin) {
	char c = ' ';
	bool mns = false;
	int a = 0;
	while (!isdigit(c)) {
		mns = c == '-';
		c = _getc_nolock(streamin);
	}
	while (isdigit(c)) {
		a *= 10;
		a += c - '0';
		c = _getc_nolock(streamin);
	}
	return (mns ? -a : a);
}

inline void FastOut(int val, FILE* streamout = stdout) {
	if (val < 0) {
		val = -val;
		_putc_nolock('-', streamout);
	}
	bool fst = true;
	const int degree = 1000000000;
	for (int i = degree; i > 0; i /= 10) {
		int dl = val / i;
		if (dl || !fst) {
			_putc_nolock('0' + dl, streamout);
			fst = false;
		}
		val %= i;
	}
	if (fst)
		_putc_nolock('0', streamout);
	_putc_nolock('\n', streamout);
}

int main() {
	start();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		int ax, bx, cx;
		ax = bx = cx = 0;
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'R')
				++ax;
			else if (s[i] == 'P')
				++bx;
			else
				++cx;
		}
		int wins = min(a, cx) + min(b, ax) + min(c, bx);
		if (wins >= n / 2 + n % 2) {
			cout << "YES\n";
			int ay, by, cy;
			ay = min(a, cx);
			by = min(b, ax);
			cy = min(c, bx);

			a -= min(a, cx);
			b -= min(b, ax);
			c -= min(c, bx);
			for (int j = 0; j < n; ++j) {
				if (s[j] == 'R' && by) {
					--by;
					cout << 'P';
				}
				else if (s[j] == 'P' && cy) {
					--cy;
					cout << 'S';
				}
				else if (s[j] == 'S' && ay) {
					--ay;
					cout << 'R';
				}
				else {
					if (a) {
						--a;
						cout << 'R';
					}
					else if (b) {
						--b;
						cout << 'P';
					}
					else {
						--c;
						cout << 'S';
					}
				}
			}
			cout << '\n';
		}
		else
			cout << "NO\n";
	}
	return 0;
}
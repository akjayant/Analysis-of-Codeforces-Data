#include <algorithm>
#include <cassert>
#include <fstream>
#include <utility>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second

#pragma warning(disable:4996)

using namespace std;

template<class T> inline void chkmin(T &a, T b) {
	if (a > b) a = b;
}

template<class T> inline void chkmax(T &a, T b) {
	if (a < b) a = b;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

#include <iostream>
//const string FILENAME = "test";
//ifstream cin(FILENAME + ".in");
//ofstream cout(FILENAME + ".out");

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int qqq = 0; qqq < T; ++qqq) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int a1 = (a + c - 1) / c;
		int b1 = (b + d - 1) / d;
		if (a1 + b1 > k) {
			cout << "-1\n";
		} else {
			cout << a1 << " " << b1 << '\n';
		}
	}
}


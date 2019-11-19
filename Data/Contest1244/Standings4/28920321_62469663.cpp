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
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool have1 = false;
		int l = n, r = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') continue;
			if (l > i) l = i;
			if (r < i) r = i;
			have1 = true;
		}
		if (!have1) {
			cout << n << '\n';
			continue;
		}
		cout << 2 * max(n - l, r + 1) << '\n';
	}
}


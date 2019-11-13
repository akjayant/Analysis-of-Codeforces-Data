/*
Московченко Иван Дмитриевич
Лабораторная работа №7
*/

#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:32100000")
#pragma GCC optimize("O3")

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <cstring>
#include <cassert>
#include <fstream>
#include <map>
#include <unordered_map>
#include <deque>
#include <unordered_set>

using namespace std;

#define inf 1000000007
#define eps 1e-9
#define mp(a, b) make_pair(a, b)
#define llinf 1000000000000000007LL

typedef long long ll;
typedef unsigned u;
typedef long double ld;
typedef unsigned char uc;
typedef unsigned long long ull;


void solve() {
	int n, a, b, c;
	string str;
	cin >> n >> a >> b >> c >> str;
	string ans(n, '.');
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'R') {
			if (b) {
				b--;
				ans[i] = 'P';
				t++;
			}
		}
		if (str[i] == 'P') {
			if (c) {
				c--;
				ans[i] = 'S';
				t++;
			}
		}
		if (str[i] == 'S') {
			if (a) {
				a--;
				ans[i] = 'R';
				t++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == '.') {
			if (a) {
				a--;
				ans[i] = 'R';
			}
			else if (b) {
				b--;
				ans[i] = 'P';
			}
			else if (c) {
				c--;
				ans[i] = 'S';
			}
		}
	}
	if (t * 2 < n) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n" << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cout.precision(9);
	srand(time(0));

	int q;
	cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}
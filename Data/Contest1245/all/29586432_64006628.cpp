//============================================================================
// Name        : codeforces.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stack>
using namespace std;

typedef long long ll;
const int MAX = 105;
const int INF = 1e9;

#define start first
#define finish second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

int n, m, a, b, c;
char s[MAX], r[MAX];
bool ch[MAX];
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a >> b >> c;
		cin >> s;
		int win = 0;
		for (int i = 0; i < n; i++) {
			ch[i] = false;
			if (s[i] == 'S' && a > 0) {
				r[i] = 'R';
				ch[i] = true;
				a--;
				win++;
			}
			if (s[i] == 'R' && b > 0) {
				r[i] = 'P';
				ch[i] = true;
				b--;
				win++;
			}
			if (s[i] == 'P' && c > 0) {
				r[i] = 'S';
				ch[i] = true;
				c--;
				win++;
			}
		}
		if (win * 2 >= n) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				if (!ch[i]) {
					if (a > 0) {
						r[i] = 'R';
						a--;
					} else if (b > 0) {
						r[i] = 'P';
						b--;
					} else if (c > 0) {
						r[i] = 'S';
						c--;
					}
				}
				cout << r[i];
			}
			cout << endl;
		} else
			cout << "NO" << endl;
	}
	return 0;
}

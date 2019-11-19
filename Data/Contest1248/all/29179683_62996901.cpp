#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <set>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;
 
ll n, m, d[1000000][4], d_bw[1000000][4], d_wb[1000000][4];

int process (string s) {
	int balance = 0, min_balance = 0, ans = 0;

	for (char c : s) {
		if (c == '(') balance++;
		else balance--;
		min_balance = min (min_balance, balance);
	}

	if (balance) return 0;

	int ptr = 0, cnt = 0;
	balance = 0;

	while (cnt != min_balance) {
		if (s[ptr] == ')') balance--;
		else balance++;

		if (balance < 0) {
			cnt--;
			balance++;
		}
		ptr++;
	}

	string t;

	for (int i = ptr; i < s.length (); i++)
		t += s[i];
	for (int i = 0; i < ptr; i++)
		t += s[i];

	balance = 0;

	for (char c : t) {
		if (c == '(') balance++;
		else balance--;
		if (!balance) ans++;
	}

	return ans;
}

int main () {
	string s;
	cin >> n;
	cin >> s;

	int ans = process (s), l = 0, r = 0;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			swap (s[i], s[j]);
			int t = process (s);

			if (t > ans) {
				l = i;
				r = j;
				ans = t;
			}

			swap (s[i], s[j]);
		}

	cout << ans << '\n' << l + 1 << ' ' << r + 1 << endl;
}
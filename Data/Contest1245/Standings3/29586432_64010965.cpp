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
const int MAX = 100005;
const int INF = 1e9;

const ll MOD = 1e9 + 7;

#define start first
#define finish second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

int n;
char s[MAX];
ll dp[MAX];
bool ch[MAX];

ll solve(int i) {
	if (i == n) {
		return 1;
	}
	if (ch[i]) {
		return dp[i];
	}
	ch[i] = true;
	dp[i] = solve(i + 1);
	if (i < n - 1 && (s[i] == 'n' || s[i] == 'u') && s[i + 1] == s[i]) {
		dp[i] = (dp[i] + solve(i + 2)) % MOD;
	}
	return dp[i];
}

int main() {
	cin >> s;
	n = strlen(s);
	bool hasSol = true;
	for (int i = 0; i < n && hasSol; i++) {
		if (s[i] == 'w' || s[i] == 'm') {
			hasSol = false;
		}
	}
	if (!hasSol)
		cout << 0 << endl;
	else {
		cout << solve(0) << endl;
	}
	return 0;
}

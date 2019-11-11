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

#define start first
#define finish second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

int n,m;
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		if(__gcd(n,m) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	return 0;
}

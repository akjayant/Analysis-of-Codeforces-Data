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

ll gcd(ll a, ll b) {
	if (!b) {
		return a;
	}
	else {
		return gcd(b, a % b);
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
		ll a, b;
		cin >> a >> b;
		if (gcd(a, b) == 1) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}
	}
	return 0;
}
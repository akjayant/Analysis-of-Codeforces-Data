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


ll fib[2000005];
string str;
const ll mod = 1'000'000'007LL;
ll len[2000005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cout.precision(9);
	srand(time(0));
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 200005; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}

	cin >> str;
	if (str.find('w') != str.npos || str.find('m') != str.npos) {
		cout << "0";
		return 0;
	}
	ll ans = 1LL;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'n') {
			int len = 1;
			for (i++; i < str.size() && str[i] == 'n'; i++, len++);
			i--;
			ans = (1LL * ans * fib[len]) % mod;
		}

		if (str[i] == 'u') {
			int len = 1;
			for (i++; i < str.size() && str[i] == 'u'; i++, len++);
			i--;
			ans = (1LL * ans * fib[len]) % mod;
		}
	}

	cout << ans;
	return 0;
}
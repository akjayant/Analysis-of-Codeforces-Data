#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <cstdio>
#include <cstring>
#include <string>
#include <string.h>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <unordered_map>
#define eps 1e-7
#define SIZE 1001000
#define rep(i, a, b) for (long long i = a; i <= b; ++i)
#define pi acos(-1.0)
#define mp make_pair
#define ll long long
using namespace std;
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll n, m, t, k;
ll a[SIZE];
int main() {
	ll xx = 0, yy = 0;
	io(); cin >> n;
	rep(i, 1, n)cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, (n / 2)) xx += a[i];
	rep(i, (n / 2 + 1), n) yy += a[i];
	cout << xx * xx + yy * yy;
}
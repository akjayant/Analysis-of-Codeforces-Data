//#define NDEBUG
#define REL
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <climits>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define nn "\n"
#define pp " "

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

template <typename T>
bool uax(T &a, const T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T>
bool uin(T &a, const T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
	in >> p.first >> p.second;
	return in;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p) {
	out << p.first << ' ' << p.second;
	return out;
}

mt19937 rnd(1928);

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

ll norm(ll x) {
	while (x < 0) x += MOD;
	if (x >= MOD) x %= MOD;
	return x;
}

int dp[N];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("linkcut.in", "r", stdin);
	//freopen("linkcut.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	dp[0] = dp[1] = 1;
	for (int i = 2; i < N; i++) {
		dp[i] = norm(dp[i - 1] + dp[i - 2]);
	}
	string s;
	cin >> s;
	ll ans = 1;
	char cur = char(0);
	int r = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0;
			exit(0);
		}
		if (s[i] == cur) {
			r++;
		}
		else {
			if (cur == 'n' || cur == 'u') ans = norm(ans * dp[r]);
			if (s[i] == 'n' || s[i] == 'u') cur = s[i];
			else cur = char(0);
			r = 1;
		}
	}
	if (cur == 'n' || cur == 'u') ans = norm(ans * dp[r]);
	cout << ans;
}
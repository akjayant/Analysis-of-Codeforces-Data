
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include <sstream>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <set>

using  namespace std;
#define ll long long


int main() {
	ll mod = 1e9 + 7;
	int n;
	string s;
	cin >> s;
	n = s.size();
	vector<ll> f(n + 1);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= mod;
	}
	ll ans = 1;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'u') num1++;
		if (s[i] == 'n') num2++;
		if (s[i] != 'n') {
			ans *= f[num2];
			num2 = 0;
		}
		if (s[i] != 'u') {
			ans *= f[num1];
			num1 = 0;
		}
		ans %= mod;
		if (s[i] == 'm') {
			cout << 0;
			return 0;
		}
		if (s[i] == 'w') {
			cout << 0;
			return 0;
		}

	}
	ans *= f[num1];
	ans %= mod;
	ans *= f[num2];
	ans %= mod;
	cout << ans;
}
#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll poww(ll a, ll b) {
	ll ans = 1, base = a;
	while (b != 0) {
		if (b & 1 != 0)
		{
			ans *= base;
			ans %= MOD;
		}
		base *= base;
		base %= MOD;
		b >>= 1;
	}
	ans %= MOD;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n, m;
	cin >> n >> m;

	ll ans = poww(2, m);
	ans = (ans + MOD - 1) % MOD;
	ll finall = poww(ans, n);
	finall %= MOD;

	cout << finall << endl;

	return 0;
}
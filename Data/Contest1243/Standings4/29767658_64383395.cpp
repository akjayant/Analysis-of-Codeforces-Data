#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stdio.h>
#include <stack>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <functional>
#define f(n) for(ll i=0;i<n;i++)
#define mp make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF 2e9
#define MOD 1000000007  //998244353
#define eps 0.00001
#define pi 3.1415926535

inline int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}

inline int norm(int a) {
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

inline int binPow(int a, int k) {
	int ans = 1;
	while (k > 0) {
		if (k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}

inline int subtract(int a, int b) {
	return norm(a - b);
}

inline int sum(int a, int b) {
	return int((a + b) % MOD);
}

inline int inv(int a) {   //a/k=a*inv(k) divizion with MOD q^-1
	return binPow(a, MOD - 2);
}

//**************************************START*****************************
ll gcd(ll a, ll b) {
	if (a == 0)return b;
	return gcd(b%a, a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		ll n;
		cin >> n;
		vector<int>rr;
		string s, t;
		cin >> s >> t;
		int r = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] != t[j]) {
				r++;
				rr.push_back(j);
			}
		}
		if (r == 0) {
			cout << "Yes\n";
			continue;
		}
		if (r > 2 || r == 1) {
			cout << "No\n";
			continue;
		}

		swap(s[rr[0]], t[rr[0]]);
		if (s == t) {
			cout << "Yes\n";
			continue;
		}
		swap(s[rr[0]], t[rr[0]]);
		swap(s[rr[1]], t[rr[1]]);
		if (s == t) {
			cout << "Yes\n";
			continue;
		}
		swap(s[rr[1]], t[rr[1]]);
		swap(s[rr[0]], t[rr[1]]);
		if (s == t) {
			cout << "Yes\n";
			continue;
		}
		swap(s[rr[0]], t[rr[1]]);
		swap(s[rr[1]], t[rr[0]]);
		if (s == t) {
			cout << "Yes\n";
			continue;
		}
		swap(s[rr[1]], t[rr[0]]);

		cout << "No\n";
	}
}
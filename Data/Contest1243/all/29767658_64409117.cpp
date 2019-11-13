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
	cin.tie(nullptr);
	ll k;
	cin >> k;
	for (int ii = 0; ii < k; ii++) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int>s1(28);
		vector<int>t1(28);
		vector<pii>ans;
		int ok = 1;
		for (int i = 0; i < n; i++) {
			s1[s[i] - 'a']++;
			t1[t[i] - 'a']++;
		}
		for (int i = 0; i < 27; i++) {
			if ((s1[i] + t1[i]) % 2 > 0) {
				ok = 0;
				break;
			}
		}
		if (ok == 0) {
			cout << "No" << endl;
			continue;
		}






		int was = 1;
		for (int i = 0; i < n; i++) {
			was = 1;
			if (s[i] == t[i])continue;
			for (int j = i + 1; j < n; j++) {
				if (t[j] == t[i]) {
					swap(s[i], t[j]);
					ans.push_back({ i,j });
					was = 0;
					break;
				}
			}
			if (was == 1) {
				for (int j = i + 1; j < n; j++) {
					if (s[j] == t[i]) {
						swap(s[j], t[n - 1]);
						ans.push_back({ j,n - 1 });
						swap(s[i], t[n - 1]);
						ans.push_back({ i,n - 1 });
						break;
					}
					if (j == n - 1) {
						ok = 0;
					}
				}

			}
		}

		if (ok == 0) {
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first + 1 << " " << ans[i].second +1<< endl;
		}
	//	cout << s << endl << t << endl << endl;
	}

}
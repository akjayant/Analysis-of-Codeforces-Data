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
const ll mod = 1e9 + 7;
ll dp[SIZE];
ll dp2[SIZE];
int main() {
	ll xx = 0, yy = 0;
	
	io(); cin >> n >> m;
	dp[1] = 2; dp[2] = 4;//if (n < m) swap(n, m);
	rep(i, 3, 100000) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	ll ans = dp[n];
	ll pre = dp[n] + 2ll;
	//if (m == 1) cout << ans;
	//else if (m == 2) cout << pre % mod;
	//else {
		dp2[1] = ans;
		dp2[2] = pre;
		rep(i, 3, m) {
			dp2[i] = (dp2[i - 1] + dp[i - 2]) % mod;
		}
		cout << dp2[m] << endl;
	//}
}
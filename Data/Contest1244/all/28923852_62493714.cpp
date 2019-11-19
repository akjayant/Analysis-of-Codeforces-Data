#define _CRT_SECURE_NO_WARNINGS

/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/

#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <math.h>
#include <bitset>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <stack>
#include <random>
#include <tuple>
#include <string.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pp;
typedef tuple<int, int, int> tt;
typedef unsigned int ui;

const int inf = (int)1e9;
const int mod = inf + 7;
//const int mod = 998244353;
//const ll inf = (ll)1e18;

#define umap unordered_map
#define Power ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()


int main() {

	Power;

	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(all(a));
	ll sum = 0;
	for (auto it : a)
		sum += it;

	vector<int> b(n);
	b = a;
	reverse(all(b));

	int l = -1;
	int r = inf + 1;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		int j = 0;
		ll sr = sum;
		ll sl = 0;
		ll ans = -1;
		for (int i = 0; i < n; i++) {
			while (j < n && a[j] - a[i] <= m)
				sr -= a[j++];
			ll cnt = 1LL * i*a[i] - sl + sr - 1LL*(n-j)*(a[i] + m);
			if (ans == -1 || cnt < ans)
				ans = cnt;
			sl += a[i];
		}

		j = 0;
		sr = sum;
		sl = 0;

		for (int i = 0; i < n; i++) {
			while (j < n && b[i] - b[j] <= m)
				sr -= b[j++];
			ll cnt = sl - 1LL * i*b[i] + 1LL * (n - j)*(b[i] - m) - sr;
			if (ans == -1 || cnt < ans)
				ans = cnt;
			sl += b[i];
		}

		if (ans > k)
			l = m;
		else
			r = m;
	}

	cout << r;

	return 0;
}
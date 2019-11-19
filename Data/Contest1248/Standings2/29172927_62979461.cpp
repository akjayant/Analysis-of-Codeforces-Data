#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
 
int a[N];

signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n, s = 0, t = 0;	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], s += a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n/2; i++)
		s -= a[i], t += a[i];
	cout << s*s + t*t;
	return 0;
}
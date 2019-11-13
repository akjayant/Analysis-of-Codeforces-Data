#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,mmx,abm,popcnt")
using namespace std;
#define fs first
#define sc second
typedef long long ll;
typedef long double ld;
mt19937 rng(time(NULL));
const int maxn = 1e3 + 100;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ld eps = 1e-9;

int main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k;
	cin>>k;
	while (k--) {
		 int n;
		 cin>>n;
		 vector<int> a(n);
		 for (int i = 0;i<n;++i) cin>>a[i];
		sort(a.begin(), a.end());
		int mx = 0;
		for (int i = 0;i<n;++i) {
			mx = max(mx, min(n-i, a[i]));
		}
		cout<<mx<<endl;
	}
	return 0;
}
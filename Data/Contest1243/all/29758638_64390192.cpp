#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<cstdio>
#include<unordered_map>
#include<cassert>

using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")

#define int long long
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define MP make_pair
#define pb push_back
#define fs first
#define sc second
#define pii pair<int, int> 
#define forn(i,n) for(int i=0; i<n; i++)
#define per(i, s, e) for(int i = s; i >= e; i--)
#define rep(i, s, e) for(int i = s; i <= e; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define precision   cout << setprecision(20) << fixed
#define sz(x) (int)(x).size()
#define vi vector<int>
#define vvi vector<vi>
#define double long double


const int MOD = 1e9 + 7;
const double PI = atan2(0, -1);
const int inf = 1e9 + 123;
const long long infl = 2e18;
const double eps = 1e-8;

int gcd(int a, int b) {
	return a ? gcd(b%a, a) : b;
}

signed main() {
	fastio;
	
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector<pair<int, int>>ans;
		bool gg = true;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i])
				continue;
			bool ok = false;
			for (int j = i + 1; j < n; j++) {
				if (b[j] == a[i]) {
					swap(a[j], b[j]);
					ans.pb(MP(j, j));
				}
				if (a[j] == a[i]) {
					swap(b[i], a[j]);
					ans.pb(MP(j, i));
					ok = true;
					break;
				}
			}
			if (!ok)
				gg = false;
		}
		if (!gg)
			cout << "NO\n";
		else {
			cout << "YES\n" << sz(ans) << '\n';
			for (auto i : ans)
				cout << i.fs + 1 << " " << i.sc + 1 << '\n';
		}
	}
}
#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define int long long

using namespace std;
typedef vector <int> vi;
typedef pair<int,int> pii;
inline void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

int gcd(int a, int b) {
	while(b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


void solve() {
	int a, b;
	cin >> a >> b;
	if(gcd(a, b) == 1) {
		cout << "Finite\n";
	} else {
		cout << "Infinite\n";
	}
}


// #define lolipop

signed main() {
#ifdef lolipop
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	fastio();
	int t; cin >> t; while(t--)solve();

}
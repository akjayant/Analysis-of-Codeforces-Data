#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 5;

void solve (){
	int n;
	cin >> n;
	vector <int> a(n);
	for (auto & x : a)
		cin >> x;
	sort (a.begin(), a.end());
	int ans = 0;
	for (int i=n-1; i>=0; --i){
		ans = max (ans, min (a[i], (n-i)));
	}
	cout << ans << '\n';
}

signed main (void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
}


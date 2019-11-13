#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define tc(t) int t;cin >> t; while(t--)
#define pb push_back
#define fi first
#define se second
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cerr << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

int main() {_
	tc(t) {
		int n;
		cin >> n;
		int a[n] = {};
		
		for(int i = 0; i<n; i++) cin >> a[i];
		int ans = 0;
		
		sort(a, a+n);
		for(int i = 0; i<n; i++) {
			int len = min((n - i), a[i]);
			ans = max(ans, len);
		}
		cout<<ans<<'\n';
	}
	return 0;
}


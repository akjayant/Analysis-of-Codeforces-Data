#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vi a(n);
		int even = 0, odd = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] % 2 == 0) even++;
			else odd++;
		}
		int m; cin >> m;
		vi b(m);
		ll ans = 0;
		for (int i = 0; i < m; i++){
			cin >> b[i];
			if (b[i] % 2 == 0) {
				ans += even;
			}
			else ans += odd;
		}
		cout << ans << endl;
	}
	return 0;
}


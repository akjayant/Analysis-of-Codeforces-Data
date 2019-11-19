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

	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll hor = 0, ver = 0;
	for (int i = n - 1; i >= n / 2; i--){
		hor += a[i];
	}
	for (int i = n / 2 - 1; i >= 0; i--){
		ver += a[i];
	}
	ll ans = (hor * hor) + (ver * ver);
	cout << ans << endl;
	
	return 0;
}


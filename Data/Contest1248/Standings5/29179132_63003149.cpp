#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int mod = 1e9 + 7;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	ll start = 2;
	vll fib(max(n, m) + 1);
	fib[0] = 2;
	fib[1] = 2;
	for (int i = 2; i <= max(n, m); i++){
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
 	}
 	
	for (int i = 1; i < n; i++){
		start = (start + fib[i - 1]) % mod;
	}
	ll ans = start;
	for (int i = 1; i < m; i++){
		ans = (fib[i - 1] + ans) % mod;
	}
	cout << ans << endl;
	return 0;
}


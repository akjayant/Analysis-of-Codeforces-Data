#include <bits/stdc++.h>
using namespace std;

int main() {
	int const MOD = 1000000007;
	int n, m;
	long long memo[100005];
	cin>>n>>m;
	memo[1] = 2;
	memo[2] = 4;	
	for(int i = 3; i <= max(n,m); i++) {
		memo[i] = (memo[i-2] + memo[i-1]) % MOD;
	}
	long long ans = memo[n];
	if(m > 1) {
		ans = (ans + 2) % MOD;
		m--;
		for(int i = 0; i < m; i++) {
			ans = (ans + memo[i]) % MOD;
		}
	}
	cout<<ans<<endl;
}

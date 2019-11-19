// Competitive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll compute_dp(int a) {
	if (a < 3) return a*2;
	vector<ll> old = { 1,1,1,1 };
	vector<ll> nw = { 0,0,0,0 };
	for (int i = 2; i < a; i++) {
		nw[0] = (old[1] + old[3])%mod;
		nw[1] = old[3];
		nw[2] = old[0];
		nw[3] = (old[0] + old[2])%mod;
		swap(nw, old);
	}
	return (old[0] + old[1] + old[2] + old[3]) % mod;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	ll res = (compute_dp(n) - 2 + compute_dp(m))%mod;
	cout << res << endl;
	return 0;
}
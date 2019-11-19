#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 9, P = 1e9 + 7;
ll n, m, f[N]; 
int main() {
	register ll i;
	cin >> n >> m;
	f[1] = 2, f[2] = 4;
	for (i = 3; i <= max(n, m); i ++) f[i] = (f[i - 1] + f[i - 2]) % P;
	cout << (f[n] + f[m] - 2 + P) % P;
	return 0;
} 
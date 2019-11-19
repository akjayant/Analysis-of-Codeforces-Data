#include "bits/stdc++.h"
using namespace std;
 
const int N = 1e5 + 5;

//2,4,6,10,16,26,42
//4,6,8,12,18,28,44
//6,8,10,14,20,30,46
//10,12,14,18,24,
//16,
//26,
const int md = 1e9 + 7;
int add(int a, int b) {
	a += b;
	if(a >= md) {
		a -= md;
	}
	return a;
}
 
int mul(int a, int b) {
	return (1LL * (a % md) * (b % md)) % md;
}

int sub(int a, int b) {
	return (a - b + md) % md;
}
 
int f[N];
 
void solve() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
 
	int n , m;
	cin >> n >> m;
 
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i < N; ++i) {
		f[i] = add(f[i - 1], f[i - 2]);
	}
 
	int ans = mul(2, f[m]);
	ans = add(ans, mul(2, f[n]));
	ans = sub(ans, 2);
	cout << ans << endl;
 
}
 
int main() {
	solve();
	return 0;  
}

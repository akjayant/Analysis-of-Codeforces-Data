#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

vector<ll> ww(110000), wb(110000), bw(110000), bb(110000);
const ll mod = 1e9 + 7;

int main() {
	int n, m; cin >> n >> m;
	if (n == m && n == 1) { cout << 2 << endl; return 0; }
	int ma = max(n, m);
	int mi = min(n, m);
	ww[2] = 1;
	wb[2] = 1;
	bw[2] = 1;
	bb[2] = 1;
	for (int i = 3; i <= ma; i++) {
		ww[i] = bw[i - 1];
		bw[i] = (bb[i - 1] + wb[i - 1])%mod;
		wb[i] = (ww[i - 1] + bw[i - 1])%mod;
		bb[i] = wb[i - 1];
	}
	ll total_bi = (wb[ma] + ww[ma] + bw[ma] + bb[ma]-2+mod) % mod;
	ll total_other = (wb[mi] + ww[mi] + bw[mi] + bb[mi]) % mod;
	cout << (total_bi + (mi==1?2:total_other)) % mod;

}
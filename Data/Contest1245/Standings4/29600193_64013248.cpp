#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define esp 1e-6

typedef long long ll;
using namespace std;

ll pow_m (ll a,ll b,ll mod) {
	ll res = 1;
	a = a % mod;
	while (b) {
		if(b & 1)	res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

const int mod = 1e9 + 7, N = 1e5 + 7;
long long arr[N] = { 0, 1, 2, 3};
void fabniq() {
	for (int i = 3; i < N; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
	}
}	
int cnt = 0;
string str;
int main() {
	fabniq();	
	cin >> str;
	long long ans = 1;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == 'm' || str[i] == 'w') 
		return cout << 0 << endl, 0;

		if (str[i] == 'u') {
			cnt = 0;
			while (i < len && str[i] == 'u') 
				i++, cnt++;		
			ans *= arr[cnt],ans %= mod,	i--;
		}
		else if (str[i] == 'n') {
			cnt = 0;
			while (i < len && str[i] == 'n') 	i++, cnt++;
			ans *= arr[cnt], ans %= mod, i--;
		}
	}
	cout << ans << endl;
	return 0;
}

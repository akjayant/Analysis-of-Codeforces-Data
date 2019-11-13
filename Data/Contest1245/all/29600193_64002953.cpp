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

int arr[1007];

int main(void)
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int a, b, flag = 0;
		memset (arr, 0, sizeof arr);
		cin >> a >> b;
		if (__gcd (a, b) == 1)
		puts("Finite");
		else 
			puts("Infinite");
	}
	return 0;
}

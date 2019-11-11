#include <cstdio>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
long long mod = 1e9 + 7;
long long f[maxn];
int main(void) {

	string s;
	cin >> s;
	int n = s.length();

	f[2] = 2;
	f[3] = 3;
	for (int i = 4; i < maxn; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	
	long long res = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0;
			return 0;
		}
	}
	for (int i = 0; i + 1 < n; ) {
		if (s[i] == 'u' && s[i + 1] == 'u') {
			int cur = 2;
			int j = i + 2;
			for (; j < n && s[j] == 'u'; j++) {
				cur++;
			}
			i = j;
			res = res * f[cur] % mod;
		} else if (s[i] == 'n' && s[i + 1] == 'n') {
			int cur = 2;
			int j = i + 2;
			for (; j < n && s[j] == 'n'; j++) {
				cur++;
			}
			i = j;
			res = res * f[cur] % mod;
		} else {
			i++;
		}
	}
	cout << res;

	return 0;
}
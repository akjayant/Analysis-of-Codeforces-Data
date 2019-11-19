#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
//int cnt[26];
//int main(void) {
//	int k;
//	cin >> k;
//	while (k--) {
//		int n;
//		cin >> n;
//		string s, t;
//		cin >> s >> t;
//		for (int i = 0; i < n; i++) {
//			cnt[s[i] - 'a']++;
//			cnt[t[i] - 'a']++;
//		}
//		bool can = true;
//		for (int i = 0; i < n; i++) {
//			if (cnt[i] % 2 != 0) {
//				can = false;
//				break;
//			}
//		}
//		if (can) {
//			cout << "Yes" << endl;
//			vector<pair<int, int>> p;
//			for (int i = 0; i < n; i++) {
//				if (s[i] != t[i]) {
//					p.emplace_back(s[i] - 'a', t[i] - 'a');
//				}
//			}
//
//		} else {
//			cout << "No" << endl;
//		}
//	}
//	return 0;
//}

const int maxn = 1000000 + 5;
int main(void) {
	long long n;
	cin >> n;
	bool prime = true;
	
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	if (n == 1) prime = false;
	if (prime) {
		cout << n << endl;
	} else {
		vector<int> primes;
		for (long long i = 2; i < maxn; i++) {
			if (n % i == 0) {
				primes.push_back(i);
				while (n % i == 0) {
					n /= i;
				}
			}
		}
		if (n > 1) primes.push_back(n);
		
		if (primes.size() == 1) {
			cout << primes[0] << endl;
		} else {
			cout << 1 << endl;
		}
	}


	return 0;
}
#include <bits/stdc++.h>

using namespace std;



void prepare() {
	
}

void read() {
	
}

void solve() {
	long long n;
	scanf("%lld", &n);
	vector<pair<long long, int>> primes;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			pair<long long, int> prime = make_pair(i, 0);
			while (n % i == 0) {
				prime.second++;
				n /= i;
			}
			primes.push_back(prime);
		}
	}	
	if (n != 1) {
		primes.push_back(make_pair(n, 1));
	}
	if (primes.size() == 1) {
		printf("%lld\n", primes[0].first);
	} else {
		printf("1\n");
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	read();
	solve();
	
	return 0;
}




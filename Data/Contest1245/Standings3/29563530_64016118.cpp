#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

long long fib(int n) {
	long long a = 1;
	long long b = 1;

	for(int i = 0; i < n; i++) {
		a += b;
		a %= mod;

		swap(a, b);
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	s += '0';

	bool bad = false;

	vector<int> lens;
	char prev = 0;
	int count = 0;
	for(char c : s) {
		if(c == 'm' || c == 'w') {
			bad = true;
			break;
		}

		if(c != prev) {
			if(prev == 'u' || prev == 'n') {
				lens.push_back(count);
			}

			prev = c;
			count = 0;
		}

		count++;
	}

	if(bad) {
		cout << 0 << endl;
		return 0;
	}

	long long mult = 1;
	for(long long len : lens) {
		mult *= fib(len);
		mult %= mod;
	}

	cout << mult << endl;

	return 0;
}

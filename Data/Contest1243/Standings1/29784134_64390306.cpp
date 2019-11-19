#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v;

int main() {

	cin >> n;
	int kol = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			v.push_back(i);
			if (n/i != i) v.push_back(n/i);
		}
		//cout << i << endl;
	}
	
	if (v.size() == 0) {
		cout << n;
		return 0;
	}
	
	for (int i = 1; i < v.size(); i++) {
		if (v[i] % v[0] != 0) {
			cout << 1;
			return 0;
		}
	}
	cout << v[0];

	return 0;
}

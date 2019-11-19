#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	long long n;
	cin >> n;
	vector <long long> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long a = 0;
	long long b = 0;

	for(int i = 0; i < n; i++) {
		if(i < (n / 2)) a += v[i];
		else b += v[i];
	}
	long long ans = a * a + b * b;
	cout << ans << endl;

	return 0;
}

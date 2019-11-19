#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		if (i < n / 2)
			sum1 += v[i];
		else
			sum2 += v[i];
	}
	cout << (sum1 * sum1 + sum2 * sum2);
}
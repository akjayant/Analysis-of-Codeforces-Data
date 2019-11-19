#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n; vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll x = 0, y = 0;
	for (int i = 0; i < n / 2; i++) {
		y += a[i];
	}
	for (int i = n/2; i < n; i++) {
		x += a[i];
	}
	cout << x * x + y * y << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long double ld;

ll bin_pow(ll a, ll n, ll mod) {
	if (n == 0)return 1;
	if (n & 1) {
		return (a * bin_pow(a, n - 1, mod)) % mod;
	}
	else {
		ll tmp = bin_pow(a, n / 2, mod);
		return (tmp * tmp) % mod;
	}
}

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int>arr(n);
	ll sum1 = 0, sum2 = 0;
	for (int& i : arr)cin >> i;
	sort(rall(arr));
	for (int i = 0; i < n / 2; i++) {
		sum1 += arr[i];
		sum2 += arr[n - i - 1];
	}
	if (n % 2)sum1 += arr[n / 2];
	cout << sum1 * sum1 + sum2 * sum2 << '\n';
	return 0;
}
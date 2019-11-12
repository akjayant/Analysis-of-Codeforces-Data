#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1000 + 10;

int n;
int k;
int arr[maxn];
int ansv[11];

signed main() {
	cin >> k;
	for (int c = 0; c < k; c++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort (arr, arr + n);
		int ans = 0;
		while (arr[n - ans] >= ans) {
			ans++;
		}
		ans--;
		ansv[c] = ans;
	}
	for (int i = 0; i < k; i++) {
		cout << ansv[i] << '\n';
	}
}

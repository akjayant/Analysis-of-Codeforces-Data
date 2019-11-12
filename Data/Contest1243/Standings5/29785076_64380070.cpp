#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k, n, res;
	cin >> k;
	while (k--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, min(arr[i], n - i));
		cout << res << endl;
	}
	return 0;
}
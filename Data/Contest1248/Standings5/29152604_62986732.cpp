#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	reverse(arr, arr + n);

	unsigned long long xs = 0, ys = 0;

	int xCnt = ceil(n / 2.0);
	for (int i = 0; i < n; i++) {
		if (i < xCnt) {
			xs += arr[i];
		}
		else {
			ys += arr[i];
		}
	}

	cout << xs * xs + ys * ys << "\n";
}
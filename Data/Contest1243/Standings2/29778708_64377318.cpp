#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

int arr[MAX];


signed main() {
	int t;

	cin >> t;

	while (t--) {
		int n;
	
		cin >> n;
	
		for (int i=0 ; i<n ; ++i)
			cin >> arr[i];
	
		sort(arr, arr + n);

		int sz = 1;
		int ans = 0;
		for (int i=n-1 ; i>=0 ; --i) {
			if (arr[i] >= sz)
				ans = sz;
			sz++;
		}

		cout << ans << endl;
	}
}
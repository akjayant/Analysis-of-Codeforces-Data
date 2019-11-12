#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define fill(space,a) memset(space,a,sizeof(space))
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);

int tt;
int arr[1005];
int main()
{
	optimize();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> tt;
	while (tt--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int ans = 1;
		int mintn = arr[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			mintn = min(mintn, arr[i]);
			if (mintn >= n - i) {
				ans = max(ans, n - i);
			}
		}
		cout << ans << endl;
	}

	return 0;
}
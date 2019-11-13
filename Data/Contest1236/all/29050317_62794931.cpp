// Author : Apaar
// Built  : 17-10-2019 19:31:20

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		int a[n][n];
		cnt++;
		for (j = 0; j < n; j++) {
			if (j % 2 == 0) {
				for (i = 0; i < n; i++) {
					a[i][j] = cnt++;
				}
			}
			else {
				for (i = n - 1; i >= 0 ; i--) {
					a[i][j] = cnt++;
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}

	}
}
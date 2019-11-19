// Author : Apaar
// Built  : 20-10-2019 14:48:23

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
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		reverse(a, a + n);
		i = 0; j = n - 1;
		int z = 1;
		while (i <= j) {
			if (z) {
				ans += a[i++];
			}
			else {
				cnt += a[j--];
			}
			z ^= 1;
		}
		cout << ans*ans + cnt*cnt;
	}
}
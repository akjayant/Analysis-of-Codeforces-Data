#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int t, cnt[2][2], n, m, tmp;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			cnt[0][tmp % 2]++;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> tmp;
			cnt[1][tmp % 2]++;
		}
		long long ans = 0;
		ans = cnt[0][0] * 1LL * cnt[1][0];
		ans += cnt[0][1] * 1LL * cnt[1][1];
		cout << ans << E;
	}
	//system("pause");
	return 0;
}
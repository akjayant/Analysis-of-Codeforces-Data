#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int n, t, arr[maxn], ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = -1;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr + n, greater<int>());
		for (int i = 0; i < n; ++i) {
			ans = max(ans, min(i + 1, arr[i]));
		}
		cout << ans << endl;
	}
}
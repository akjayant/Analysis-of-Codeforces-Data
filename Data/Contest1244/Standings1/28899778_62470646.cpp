//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int t;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = n;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				ans = max(ans, max(i + 1, n - i) * 2);
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

int ans[400][400], n, cur;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= n; j++)
				ans[j][i] = ++cur;
		} else {
			for (int j = n; j >= 1; j--)
				ans[j][i] = ++cur;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}

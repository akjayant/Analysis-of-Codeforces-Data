#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int arr[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	bool flag = false;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt++;
			if (flag) arr[j][i] = cnt;
			else arr[n - j + 1][i] = cnt;
		}
		flag = !flag;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

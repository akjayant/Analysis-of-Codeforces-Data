#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int MOD = 1e9 + 7;

int main() {
	fastio;
	int n;
	cin >> n;

	int arr[300][300], f = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i & 1 ? n - j - 1 : j][i] = f++;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << arr[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
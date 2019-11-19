#include "bits/stdc++.h"
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool good(vector <vector <int> > v) {
	int n = v.size();
	int m = v[0].size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int cnt = 0;
			for(int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if(x >= 0 && y >= 0 && x < n && y < m) {
					cnt += (v[x][y] == v[i][j]);
				}
			}
			if(cnt > 1) return false;
		}
	}
	return true;
}
int get(int n, int m) {
	int x = (n * m);
	int ans = 0;
	for(int i = 0; i < (1 << x); i++) {
		vector<vector<int>> v(n, vector<int>(m));
		for(int j = 0; j < x; j++) {
			if((i & (1 << j))) {
				v[j / m][j % m] = 1;
			}
		}
		if(good(v)) {
			ans++;
		}
	}
	return ans;
}

const int N = 100005;
long long fibo[N];
const int MOD = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	fibo[0] = 1;
	fibo[1] = 1;
	for(int i = 2; i < N; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= MOD;
	}
	long long n, m;
	cin >> n >> m;
	long long ans = 2 * (fibo[n] + fibo[m]);
	ans %= MOD;
	ans -= 2;
	if(ans < 0) {
		ans += MOD;
	}
	cout << (ans % MOD) << endl;
	return 0;
}

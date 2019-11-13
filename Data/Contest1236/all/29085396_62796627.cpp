#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second
int const INF = 2e9 + 7;
int mod = 1e9 + 7;
vector<int> g[200004];
vector<int> color(200004);

signed main() {
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n));
	int ch = 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				a[i][j] = ch;
				ch++;
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				a[i][j] = ch;
				ch++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[j][i] << " ";
		}
		cout << endl;
	}
}

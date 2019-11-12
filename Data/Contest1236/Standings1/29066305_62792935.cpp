#include <bits/stdc++.h>
using namespace std;
int G[400][400];
int main() {
	int n; cin >> n;
	int c = 0;
	for(int i = 1; i <= n; i += 2) {
		for(int j = 1; j <= n; j++)
			G[i][j] = ++c;
		for(int j = n; j >= 1; j--)
			G[i+1][j] = ++c;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			cout << G[j][i] << ' ';
		cout << endl;
	}
}

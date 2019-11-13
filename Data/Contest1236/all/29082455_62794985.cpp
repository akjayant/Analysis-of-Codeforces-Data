#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define MAX 20
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> res(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        res[j][i] = i * n;
	        if (i&1) {
                res[j][i] += n - j;
	        } else {
                res[j][i] += j + 1;
	        }
	    }
	}
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cout << res[i][j] << " ";
	    }
	    cout << "\n";
	}

	return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> groups(n, vector<int>(n));

	for(int i = 0; i < n; i++) {
		int start = i*n + 1;
		int end = i*n + n+1;

		if(i % 2) {
			start = i*n + n;
			end = i*n;
		}

		int pos = 0;
		string sep = "";
		while(start != end) {
			groups[i][pos] = start;
			pos++;

			if(start < end) {
				start++;
			}
			else {
				start--;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		string sep = "";
		for(int j = 0; j < n; j++) {
			cout << sep << groups[j][i];
			sep = " ";
		}
		cout << endl;
	}

	return 0;
}

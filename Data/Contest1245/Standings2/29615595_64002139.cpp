#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

string rps;
string ans;
int avail[3], req[3];

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cin >> avail[0] >> avail[1] >> avail[2];
		cin >> rps;
		req[0] = req[1] = req[2] = 0;
		for (int i = 0; i < n; i++) {
			if (rps[i] == 'R')
				req[0]++;
			else if (rps[i] == 'P')
				req[1]++;
			else
				req[2]++;
		}
		ans.clear();
		for (int i = 0; i < n; i++) {
			ans.push_back('X');
		}
		int amt = 0;
		for (int i = 0; i < n; i++) {
			if (rps[i] == 'R'&&avail[1]) {
				amt++;
				avail[1]--;
				ans[i] = 'P';
			}
			else if (rps[i] == 'P'&&avail[2]) {
				amt++;
				avail[2]--;
				ans[i] = 'S';
			}
			else if (rps[i] == 'S'&&avail[0]) {
				amt++;
				avail[0]--;
				ans[i] = 'R';
			}
		}
		int reqamt = (n / 2) + (n & 1);
		if (amt >= reqamt) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				if (ans[i] == 'X') {
					if (avail[0]) {
						avail[0]--;
						ans[i] = 'R';
					}
					else if (avail[1]) {
						avail[1]--;
						ans[i] = 'P';
					}
					else {
						avail[2]--;
						ans[i] = 'S';
					}
				}
			}
			cout << ans << "\n";
		}
		else
			cout << "NO\n";
	}
	//system("pause");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAX_BIT = 30;
int nTest;
int l;
int r;
long long memo[MAX_BIT + 9][2][2][2][2];

int getBit(int state, int pos) {
	return state >> pos & 1;
}

long long dp(int pos, int l1, int r1, int l2, int r2) {
	if(pos < 0) {
		return 1;
	}
	long long& res = memo[pos][l1][r1][l2][r2];
	if(res != -1) {
		return res;
	}
	res = 0;
	for(int i = 0; i <= 1; i++) {
		for(int j = 0; j <= 1; j++) {
			if(i == 1 && j == 1) {
				continue;
			}
			if(l1 == 0 && i < getBit(l, pos)) {
				continue;
			}
			if(r1 == 0 && i > getBit(r, pos)) {
				continue;
			}
			if(l2 == 0 && j < getBit(l, pos)) {
				continue;
			}
			if(r2 == 0 && j > getBit(r, pos)) {
				continue;
			}
			int nxtL1 = l1;
			int nxtR1 = r1;
			int nxtL2 = l2;
			int nxtR2 = r2;
			if(i > getBit(l, pos)) {
				nxtL1 = 1;
			}
			if(i < getBit(r, pos)) {
				nxtR1 = 1;
			}
			if(j > getBit(l, pos)) {
				nxtL2 = 1;
			}
			if(j < getBit(r, pos)) {
				nxtR2 = 1;
			}
			res += dp(pos - 1, nxtL1, nxtR1, nxtL2, nxtR2);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> nTest;
	for(int iTest = 1; iTest <= nTest; iTest++) {
		cin >> l >> r;
		fill(memo[0][0][0][0], memo[MAX_BIT + 1][0][0][0], -1);
		cout << dp(MAX_BIT, 0, 0, 0, 0) << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

mt19937 gen((uint) chrono::high_resolution_clock::now().time_since_epoch().count());

ll dp[32][2][3][3][3][3];

ll solve(int l, int r) {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				for (int f = 0; f < 3; f++) {
					for (int o = 0; o < 3; o++) {
						for (int e = 0; e < 3; e++) {
							dp[i][j][k][f][o][e] = 0;
						}
					}
				}
			}
		}
	}

	string ls = bitset<32>(l).to_string();
	string rs = bitset<32>(r).to_string();
	reverse(ls.begin(), ls.end());
	reverse(rs.begin(), rs.end());

	while (ls.size() > 1 && ls.back() == '0' && rs.back() == '0') {
		ls.pop_back();
		rs.pop_back();
	}

	for (char &c : ls) {
		c -= '0';
	}

	for (char &c : rs) {
		c -= '0';
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int t1 = 0, t2 = 0;
			int tt1 = 0, tt2 = 0;

			if (i < ls[0]) {
				t1 = 0;
			} else if (i == ls[0]) {
				t1 = 1;
			} else {
				t1 = 2;
			}

			if (i < rs[0]) {
				tt1 = 0;
			} else if (i == rs[0]) {
				tt1 = 1;
			} else {
				tt1 = 2;
			}

			if (j < ls[0]) {
				t2 = 0;
			} else if (j == ls[0]) {
				t2 = 1;
			} else {
				t2 = 2;
			}

			if (j < rs[0]) {
				tt2 = 0;
			} else if (j == rs[0]) {
				tt2 = 1;
			} else {
				tt2 = 2;
			}

			if ((i + j) % 2 == (i ^ j)) {
				dp[0][(i + j) / 2][t1][tt1][t2][tt2] = 1;
			}
		}
	}

	for (int len = 1; len < ls.size(); len++) {
		for (int a = 0; a <= 1; a++) {
			for (int b = 0; b <= 1; b++) {
				for (int carry = 0; carry <= 1; carry++) {
					for (int t1 = 0; t1 <= 2; t1++) {
						for (int tt1 = 0; tt1 <= 2; tt1++) {
							for (int t2 = 0; t2 <= 2; t2++) {
								for (int tt2 = 0; tt2 <= 2; tt2++) {
									if (dp[len - 1][carry][t1][tt1][t2][tt2] == 0) {
										continue;
									}

									int T1, TT1, T2, TT2;

									if (a < ls[len]) {
										T1 = 0;
									} else if (a == ls[len]) {
										T1 = t1;
									} else {
										T1 = 2;
									}

									if (a < rs[len]) {
										TT1 = 0;
									} else if (a == rs[len]) {
										TT1 = tt1;
									} else {
										TT1 = 2;
									}

									if (b < ls[len]) {
										T2 = 0;
									} else if (b == ls[len]) {
										T2 = t2;
									} else {
										T2 = 2;
									}

									if (b < rs[len]) {
										TT2 = 0;
									} else if (b == rs[len]) {
										TT2 = tt2;
									} else {
										TT2 = 2;
									}

									int newCarry = (a + b + carry) / 2;
									int newSum = (a + b + carry) % 2;

									if (newSum == (a ^ b)) {
										dp[len][newCarry][T1][TT1][T2][TT2] += dp[len - 1][carry][t1][tt1][t2][tt2];
									}
								}
							}
						}
					}
				}
			}
		}
	}

	ll res = 0;

	for (int t1 = 1; t1 <= 2; t1++) {
		for (int tt1 = 0; tt1 <= 1; tt1++) {
			for (int t2 = 1; t2 <= 2; t2++) {
				for (int tt2 = 0; tt2 <= 1; tt2++) {
					res += dp[ls.size() - 1][0][t1][tt1][t2][tt2];
				}
			}
		}
	}

	return res;
}

void solve() {
	int l, r;
	cin >> l >> r;

	cout << solve(l, r) << "\n";

//	int res = 0;
//
//	for (int i = l; i <= r; i++) {
//		for (int j = l; j <= r; j++) {
//			if (i + j == (i ^ j)) {
//				res++;
//			}
//		}
//	}
//
//	cout << res << "\n\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--) {
		solve();
	}

	return 0;
}
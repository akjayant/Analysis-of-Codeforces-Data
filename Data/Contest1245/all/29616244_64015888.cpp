#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a1[30], a2[30];
ll dp[31][2][2];

//exclusive bound
ll calc(int r1, int r2) {
	for(int i=0; i<30; ++i) {
		a1[i]=r1>>i&1;
		a2[i]=r2>>i&1;
	}

	memset(dp, 0, sizeof(dp));
	dp[30][0][0]=1;

	for(int i=30; i; --i) {
		for(int b1=0; b1<2; ++b1) {
			for(int b2=0; b2<2; ++b2) {
				//0, 0
				dp[i-1][b1|a1[i-1]][b2|a2[i-1]]+=dp[i][b1][b2];
				//0, 1
				if(b2||a2[i-1]) {
					dp[i-1][b1|a1[i-1]][b2]+=dp[i][b1][b2];
				}
				//1, 0
				if(b1||a1[i-1]) {
					dp[i-1][b1][b2|a2[i-1]]+=dp[i][b1][b2];
				}
			}
		}
	}

	return dp[0][1][1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		cout << calc(r+1, r+1)-calc(r+1, l)-calc(l, r+1)+calc(l, l) << "\n";
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int n=10;
int h[n][n];
double dp[n][n];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> h[i][j];
		}
	}

	for(int i=0; i<n; ++i) {
		if(i%2==0) {
			//backwards
			for(int j=0; j<n; ++j) {
				if(!i&&!j) {
					continue;
				}
				int ns=!i?max(6-j, 0):0;
				double c=0;
				for(int k=1; k<=6; ++k) {
					if(!i&&j<k) {
						continue;
					}
					int ni, nj;
					if(j<k) {
						ni=i-1;
						nj=k-j-1;
					} else {
						ni=i;
						nj=j-k;
					}
					c+=min(dp[ni][nj], dp[ni-h[ni][nj]][nj])/6;
				}
				dp[i][j]=c/(1-ns/6.0)+1/(1-ns/6.0);
			}
		} else {
			//forwards
			for(int j=n-1; ~j; --j) {
				double c=0;
				for(int k=1; k<=6; ++k) {
					int ni, nj;
					if(j+k>9) {
						ni=i-1;
						nj=9-(j+k-10);
					} else {
						ni=i;
						nj=j+k;
					}
					c+=min(dp[ni][nj], dp[ni-h[ni][nj]][nj])/6;
				}
				dp[i][j]=c+1;
			}
		}
	}

	cout << fixed << setprecision(9) << dp[9][0];

	return 0;
}
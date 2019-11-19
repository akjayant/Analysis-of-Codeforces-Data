#include<bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)/2)
#define st first
#define nd second
#define ll long long
#define N 600005
#define inf 1000000000
#define MOD 1000000007
#define fast_io() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(false)
using namespace std;

int n;
ll dp[45][2][2][2][2];

ll solve(int le,int ri) {

	memset(dp,0ll,sizeof(dp));

	dp[31][0][0][0][0]=1;

	for(int b=30;b>=0;b--) {

		for(int i=0;i<2;i++) {

			for(int j=0;j<2;j++) {

				for(int k=0;k<2;k++) {

					for(int l=0;l<2;l++) {

						bool dle=(((1<<b)&le)>0);
						bool dri=(((1<<b)&ri)>0);

						// 0,0

						if((i!=0 || !dle) && (k!=0 || !dle)) {

							dp[b][i][j|dri][k][l|dri]+=dp[b+1][i][j][k][l];

						}

						// 0,1

						if((i!=0 || !dle) && (l || dri)) {

							dp[b][i][j|dri][k|(!dle)][l]+=dp[b+1][i][j][k][l];

						}

						// 1,0

						if((j || dri) && (k!=0 || !dle)) {

							dp[b][i|(!dle)][j][k][l|dri]+=dp[b+1][i][j][k][l];

						}

					}

				}

			}

		}

	}

	ll sum=0;

	for(int i=0;i<2;i++) {

		for(int j=0;j<2;j++) {

			for(int k=0;k<2;k++) {

				for(int l=0;l<2;l++) {

					sum+=dp[0][i][j][k][l];

				}

			}

		}

	}

	return sum;

}

int main() {

	scanf("%d",&n);

	for(int i=1;i<=n;i++) {

		int l,r;

		scanf("%d %d",&l,&r);

		printf("%lld\n",solve(l,r));

	}

}
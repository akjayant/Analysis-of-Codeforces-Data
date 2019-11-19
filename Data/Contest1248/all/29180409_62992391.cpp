#include <bits/stdc++.h>
using namespace std;
//mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
//int rnd(int x) { return mrand()%x;}
typedef long long ll;
const ll md=1e9+7;
ll dp[100100][5];
int main(){
	dp[1][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=100000;i++){
		dp[i][1]+=dp[i-1][0]+dp[i-1][2];
		dp[i][0]+=dp[i-1][1]+dp[i-1][3];
		dp[i][2]+=dp[i-1][0];
		dp[i][3]+=dp[i-1][1]; 
		for(int j=0;j<4;j++){
			dp[i][j]%=md;
		}
	}
	int n,m;
	scanf("%d%d",&n,&m);
	ll su=0;
	for(int i=0;i<4;i++){
		su+=dp[n][i];
		su+=dp[m][i];
		su%=md;
	}
	printf("%lld\n",(su-2+md)%md);
	return 0;
}


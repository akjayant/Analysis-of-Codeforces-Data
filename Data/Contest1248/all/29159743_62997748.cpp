#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100009;
int P=1000000007;
int dp[N][2];
int n,m;
int f(int i,int c){
	if(i<=1)
		return 1;
	if(dp[i][c]!=-1)
		return dp[i][c];
	int c1=(c+1)%2;
	dp[i][c]=(f(i-1,c1)+f(i-2,c1))%P;
	return dp[i][c];
}
int32_t main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> m;
	memset(dp,-1,sizeof(dp));
	cout << (f(n,0)+f(n,1)+f(m,0)+f(m,1)-2)%P << endl;
}
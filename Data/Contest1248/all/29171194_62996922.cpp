#include<iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 1e5+50;
ll dp[maxn][3];
int main(){
	int n,m;
	cin>>n>>m;
	dp[1][0]=2;
	dp[1][1]=0;
	for(int i=2;i<=m;i++){
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
		dp[i][0]%=mod;
		dp[i][1]%=mod;
	}
	ll a,b,c;
	a=0,b=1,c=0;
	for(int i=0;i<n;i++){
		c=a+b;
		c%=mod;
		a=b;
		b=c;
	}
	ll res = dp[m][0]+dp[m][1]-2+(b*2)%mod;
	res%=mod;
	cout<<res<<endl;
	return 0;
}
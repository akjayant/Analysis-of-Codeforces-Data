#include <bits/stdc++.h>
using namespace std;
#define asp ""
#define aps ''
#define one 1
#define two 2
#define dif !=
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 100005;
ll dp[maxn][4];

ll dfs(int n,int val){

	if(dp[n][val] dif -one) return dp[n][val];
	if(n == 0) return one;
	ll ret  = 0;
	if(val == 3){
		ret = dfs(n-one,one);
		ret %= mod;
		dp[n][val] = ret;
		return ret;
	}
	else{
		ret = dfs(n-one,3);
		ret %= mod;
		ret += dfs(n-one,one);
		ret %= mod;

		dp[n][val] = ret;

		return ret;
	}
}

ll solve(int n,int m){

	ll sum = 0;
	sum += dfs(n-one,one);
	//cout <<sum<<endl;
	sum %= mod;
	sum += dfs(m-one,one);
	//cout <<sum<<endl;
	sum %= mod;
	sum--;
	if(sum  < mod) sum += mod;

	sum %= mod;
	sum *= two;


	sum %= mod;
	return sum;
}

void init(){

	for(int i=0;i<maxn;i++){
		for(int j=0;j<4;j++){
			dp[i][j] = -one;
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	init();
	cout << solve(n,m) << endl;
}
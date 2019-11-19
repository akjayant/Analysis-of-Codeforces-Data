#include <iostream>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

const int MAXN = (int)1e5;
const ll mod = (ll)1e9 + 7;
int n, m;
ll dp[MAXN + 5][2];

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> n >> m;
dp[0][0] = dp[0][1] = 1;
for(int i = 1 ; i <= n ; ++i){
	dp[i][0] = dp[i - 1][1];
	dp[i][1] = dp[i - 1][0];
	if(i > 1){
		dp[i][0] = (dp[i][0] + dp[i - 2][1]) % mod;
		dp[i][1] = (dp[i][1] + dp[i - 2][0]) % mod;
	}
}
ll sol = (dp[n][0] + dp[n][1]) % mod;
for(int i = 1 ; i <= m ; ++i){
	dp[i][0] = dp[i - 1][1];
	dp[i][1] = dp[i - 1][0];
	if(i > 1){
		dp[i][0] = (dp[i][0] + dp[i - 2][1]) % mod;
		dp[i][1] = (dp[i][1] + dp[i - 2][0]) % mod;
	}
}
sol = (sol + dp[m][0]) % mod;
sol = (sol + dp[m][1]) % mod;
sol = (sol - 2 + mod) % mod;
cout << sol << endl;

return 0;
}


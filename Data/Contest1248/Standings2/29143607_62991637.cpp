#include <bits/stdc++.h>
#define INF 1e9+7
#define LINf 1e18+7
#define fr first 
#define sc second
#define ll long long
#define pb push_back
#define pii pair<int,int>

using namespace std;
const int mod = 1e9+7;
int n , m;
ll dp[100005];

int main(){
	ios_base::sync_with_stdio(), cin.tie() , cout.tie();
	cin >> n >> m;
	int mx = max(n,m);
	dp[0] = 1;
	dp[1] = 2;
	for(int i = 2; i <= mx ; i++){
		dp[i] = (dp[i-1] + dp[i-2])%mod;
	}
	cout << (dp[n-1]*2 +dp[m-1]*2 -2 + mod)%mod << '\n';
}
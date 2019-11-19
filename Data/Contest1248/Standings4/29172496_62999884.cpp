#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <stack>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int mod = 1e9+7;

vector<int> dp;
vector<int> verdp;
int n,m;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	dp = vector<int>(max(n,m),0);
	dp[0] = 1; dp[1] = 2;
	
	for(int i = 2;i<max(n,m);i++)
	{
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}
	
	ll ans = (2LL * (dp[m-1] -1 + dp[n-1] ) % mod) % mod;
	cout<<ans;
	
	return 0;
}
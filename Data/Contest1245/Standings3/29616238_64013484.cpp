#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int mod = 1e9+7;

string s;
int n, dp[100005];

int solve(int pos){
    if(pos == n) return 1;
    if(dp[pos] != -1) return dp[pos];
    if(s[pos] == 'm' || s[pos] == 'w') return dp[pos] = 0;
    int res = solve(pos+1);
    if(pos+1 < n and s[pos] == 'n' and s[pos+1] == 'n')
        res = (res+solve(pos+2))%mod;
    if(pos+1 < n and s[pos] == 'u' and s[pos+1] == 'u')
        res = (res+solve(pos+2))%mod;
    return dp[pos] = res;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = s.size();
    
    cout << solve(0) << endl;
 
	return 0;
}
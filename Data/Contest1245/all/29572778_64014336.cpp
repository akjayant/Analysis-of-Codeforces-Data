
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack> 
#include <map>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;


long long MOD  = 1e9 +7;



long long dp[100002];

string s;
long long solve(int in){
	if(in==-1)
		return 1;
	if(in==0)
		return 1;
	if(dp[in]!=-1)
		return dp[in];

	string ss = s.substr(in-1, 2);
	long long ans =0 ;
	if(ss=="nn" || ss=="uu")
		ans=solve(in-1)  + solve(in -2);
	else
		ans=solve(in-1);
	ans%=MOD;
	return dp[in]=ans;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	bool ok = 1;
	for(char c:s)
		if(c=='w'|| c=='m')
			ok =0;
	long long ans =0 ;
	int n = s.size();
	memset(dp, -1, sizeof dp);
	if(ok){
		ans = solve(n-1);
	}

	cout<<ans<<"\n";


	return 0;
}


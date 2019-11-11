#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define se second
#define fi first
#define pb push_back
#define eb emplace_back
#define mk make_pair

#define N 1000007 //10e6 +7
#define MOD 1000000007

ll dp[N][3];
string s;

ll go(int curr, int prev){
	if(curr>=s.size())return 1;
	ll &ret = dp[curr][prev];
	if(ret!=-1)return ret;
	ret = 0;
	if(prev == 1 and s[curr]=='u')ret = (ret + go(curr+1, 0))%MOD;
	if(prev == 2 and s[curr]=='n')ret = (ret + go(curr+1, 0))%MOD;
	if(s[curr]=='u')ret = (ret + go(curr+1, 1))%MOD;
	else if(s[curr]=='n')ret = (ret + go(curr+1, 2))%MOD;
	else ret = (ret + go(curr+1, 0))%MOD;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='m' or s[i]=='w'){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << go(0, 0) << endl;
}
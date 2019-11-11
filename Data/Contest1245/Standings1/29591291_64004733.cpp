#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

ll n, dp[MAXN], mod = 1e9 + 7, ans = 1;
string s;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    dp[0] = dp[1] = 1;
    for(int i = 2; i < MAXN; i++){
    	dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == 'm' or s[i] == 'w'){
    		cout << 0;
    		return 0;
    	}
    }
    for(int i = 0; i < s.size(); i++){
    	int c = 1;
    	while(i + 1 < s.size() and s[i + 1] == s[i]){
    		i++;
    		c++;
    	}
    	if(s[i] == 'u' or s[i] == 'n'){
    		ans *= dp[c];
    		ans %= mod;
    	}
    }
    cout << ans;
}
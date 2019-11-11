#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e6, MOD = 1e9 + 7;;
char s[N];
int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	cin >> (s + 1);
	int n = strlen(s + 1);
	vector<int> dp(n + 2);

	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0 << endl;
			exit(0);
		}
		if(s[i] == 'n' && s[i - 1] == 'n'){
			dp[i] += dp[i-2];
		}
		if(s[i] == 'u' && s[i - 1] == 'u'){
			dp[i] += dp[i-2];
		}
		dp[i] += dp[i - 1];
		dp[i] %= MOD;
	}

	cout << dp[n] << endl;

	
	return 0;
}


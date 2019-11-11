#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int N = 123456;

long long dp[N];

void prepare() {
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1];
		if (i > 1) {
			dp[i] += dp[i - 2];
			dp[i] %= mod;
		}
	}
}

void read() {
	
}

char str[123456];

void solve() {	
	scanf("%s", str);
	int n = strlen(str);
	int cnt = 0;
	char cur = 'a';	
	long long answer = 1;
	for (int i = 0; i < n; i++) {
		if (str[i] != 'u' && str[i] != 'n') {			
			answer = (dp[cnt] * answer) % mod;
			cnt = 0;
			cur = 'a';
			continue;
		}
		if (cur == str[i]) {
			cnt++;
		} else {			
			answer = (dp[cnt] * answer) % mod;
			cnt = 1;
			cur = str[i];
		}
	}
	answer = (answer * dp[cnt]) % mod;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'm' || str[i] == 'w') {
			answer = 0;
		}
	}
	printf("%lld\n", answer);
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	prepare();
	read();
	solve();
	
	return 0;
}




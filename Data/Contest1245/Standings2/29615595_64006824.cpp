#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MOD 1000000007ll

using namespace std;

typedef long long ll;
string str;
ll dp[100005];

int main() {
	ios::sync_with_stdio(0);
	cin >> str;
	int n = (int)str.size();
	for (int i = 0; i < n; i++) {
		if (str[i] == 'm' || str[i] == 'w') {
			cout << "0\n";
			return 0;
		}
	}
	dp[0] = dp[1] = 1;
	for (int i = 1; i < n; i++) {
		if (str[i] == str[i - 1] && (str[i] == 'u' || str[i] == 'n')) {
			dp[i+1] = (dp[i - 1] + dp[i]) % MOD;
		}
		else {
			dp[i + 1] = dp[i];
		}
	}
	cout << dp[n] << "\n";
	//system("pause");
	return 0;
}
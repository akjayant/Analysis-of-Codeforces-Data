#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 100000 + 100;
const int MOD = 1000000007;
bool flag;
int len;
int dp[maxn];
char str[maxn];

int main() {
	while(scanf("%s", str + 1) != EOF) {
		flag = true;
		len = strlen(str + 1);
		for(int i = 1; i <= len; ++i) {
			if(str[i] == 'm' || str[i] == 'w') {
				flag = false;
				break;
			}
		}
		if(!flag) {
			printf("0\n");
			continue;
		}
		dp[0] = dp[1] = 1;
		for(int i = 2; i <= len; ++i) {
			if(str[i] == 'u' || str[i] == 'n')  {
				if(str[i - 1] == str[i]) {
					dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
				} else {
					dp[i] = dp[i - 1];
				}
			} else {
				dp[i] = dp[i - 1];
			}
		}
		printf("%d\n", dp[len]);
	}

    return 0;
}
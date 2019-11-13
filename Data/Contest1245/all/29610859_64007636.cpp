#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(NULL);

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INT_INF = 1e9;
const ll LL_INF = 1e18;
const int MAXN = 500010;

typedef struct GE{
	int to;
	ll w;
}GE;

int n, m;
char s[MAXN];

typedef long long ll;
const ll mod = 1e9+7;

ll dp[MAXN];
int main() {
	scanf("%s", s+1);
	int sl = strlen(s+1);

	dp[0] = 1;
	bool f = false;

	for(int i=1;i<=sl;i++) {
		if(s[i]=='m' || s[i]=='w') f = true;

		if(s[i]!='n' && s[i]!='u') {
			dp[i] = dp[i-1];
		}
		else {
			if(s[i]=='n' && s[i-1]=='n') {
				dp[i] = dp[i-1] + dp[i-2];
				dp[i]%=mod;
			}
			else if(s[i]=='u' && s[i-1]=='u') {
				dp[i] = dp[i-1] + dp[i-2];
				dp[i]%=mod;
			}
			else{
				dp[i] = dp[i-1];
			}
		}
	}
	if(!f)
		printf("%lld", dp[sl]%mod);
	else
		puts("0");
	
	return 0;
}
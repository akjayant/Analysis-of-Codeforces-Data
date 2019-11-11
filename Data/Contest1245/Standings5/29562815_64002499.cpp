#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

char ch[100005];
int memo[100005];

int n;
string s;

int dp(int pos) {
	if (pos == n+1) return 0;
	if (pos == n) return 1;
	if (memo[pos]!=-1) return memo[pos];
	int sol = dp(pos+1);
	if (s[pos] == 'n' and s[pos+1] == 'n') sol+=dp(pos+2);
	if (s[pos] == 'u' and s[pos+1] == 'u') sol+=dp(pos+2);
	return memo[pos] = sol % MOD;
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%s", ch);
	s = ch;
	n = s.size();
	for (int i=0 ; i<n ; i++) {
		if (s[i] == 'w' or s[i] == 'm') {
			printf("0\n");
			return 0;
		}
	}
	printf("%d\n", dp(0));
	return 0;
}
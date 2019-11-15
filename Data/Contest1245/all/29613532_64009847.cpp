//#pragma GCC optimize(3)
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
typedef long long LL;
using namespace std;
#define MAXN 500005
#define eps (1e-11)
#define lyh 19260817
#define njj 19491001
#define pp 1000000007
const double pi = acos(-1.0);
#define P pair<int,int>
#define int LL

char s[MAXN];
int anss[MAXN];
void init(int n) {
	anss[1] = 1; anss[2] = 2;
	for (int i = 3; i <= n; i++) {
		anss[i] = anss[i - 1] + anss[i - 2];
		anss[i] %= pp;
	}
}


signed main() {
	scanf("%s", s);
	int len = strlen(s);
	bool flag = false;
	int lenn = 0;
	int lenu = 0;
	int ans = 1;
	init(len);
	anss[0] = 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] == 'm' || s[i] == 'w') flag = true;
		if (s[i] == 'n') {
			lenn++;
		}
		else {
			ans *= anss[lenn];
			ans %= pp;
			lenn = 0;
		}
		if (s[i] == 'u') {
			lenu++;
		}
		else {
			ans *= anss[lenu];
			ans %= pp;
			lenu = 0;
		}
	}
	if (flag) {
		printf("0");
	}
	else {
		printf("%lld", ans);
	}
	return 0;
}
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>

#define rep(a,b,c) for(int a=b;a<c;a++)
#define i(a) scanf("%d",&a)
#define l(a) scanf("%lld",&a)
#define INF 1000000000
typedef long long ll;
using namespace std;
ll p = 1000000007;
ll cache[100001];
ll dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 1;
	else if (x == 2) return 2;
	ll& ret = cache[x];
	if (ret != 0) return cache[x];
	return (ret = (dp(x - 1) + dp(x - 2)) % p);
}
string str;
int main(){
	memset(cache, 0, sizeof(cache));
	char c;
	int cnt = 0;
	char prev = -1;
	ll ans = 1;
	cin >> str;
	int i = 0;
	while (i<str.size()) {
		c = str.c_str()[i++];
		if (c == 'w' || c == 'm') {
			 printf("0"); return 0;
		}
		if (c == 'n') {
			if (prev == 'n') cnt++;
			else if (prev == 'u') {
				ans = (ans * dp(cnt)) % p;
				cnt = 1;
			}
			else {
				cnt = 1;
			}
		}
		else if (c == 'u') {
			if (prev == 'u') cnt++;
			else if (prev == 'n') {
				ans = (ans * dp(cnt)) % p;
				cnt = 1;
			}
			else {
				cnt = 1;
			}
		}
		else {
			if (prev == 'u') {
				ans = (ans * dp(cnt)) % p;
				cnt = 0;
			}
			else if (prev == 'n') {
				ans = (ans * dp(cnt)) % p;
				cnt = 0;
			}
		}
		prev = c;
	}
	ans = (ans * dp(cnt)) % p;
	printf("%lld", ans);
}
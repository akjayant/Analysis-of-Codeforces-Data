#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <cmath>
#include <tuple>
using namespace std;
#define fio ios::sync_with_stdio(0),cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, K, T;
ll a, b, c;
char inp[300005];
ll fibo[100005] = {1, 1};
const ll mod = 1e9 + 7;
int main() {
	scanf("%s", inp + 1);
	N = strlen(inp + 1);
	for (int i = 2; i < 100005; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
	}

	ll ret = 1;
	for (int i = 1; i <= N;) {
		char c = inp[i];
		if (c == 'u' || c == 'n') {
			ll cnt = 0;
			while (inp[i] == c) {
				cnt++; i++;
			}
			ret *= fibo[cnt];
			ret %= mod;
		}
		else if (c == 'm' || c == 'w') {
			ret = 0; i++;
		}
		else {
			i++;
		}
	}
	printf("%lld\n", ret);
}
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
int a, b, c;
char S[300005];
char ret[105];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &N, &a, &b, &c); // R P S
		scanf("%s", S + 1);
		int cnt = 0;
		memset(ret, 0, sizeof ret);
		for (int i = 1; i <= N; i++) {
			if (S[i] == 'S') {
				if (a) {
					ret[i] = 'R';
					a--;
					cnt++;
				}
			}
			else if (S[i] == 'P') {
				if (c) {
					ret[i] = 'S';
					c--;
					cnt++;
				}
			}
			else {
				if (b) {
					ret[i] = 'P';
					b--;
					cnt++;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			if (!ret[i]) {
				if (a) ret[i] = 'R', a--;
				else if (b) ret[i] = 'P', b--;
				else ret[i] = 'S', c--;
			}
		}
		if (cnt >= (N + 1) / 2) {
			puts("YES");
			puts(ret + 1);
		}
		else {
			puts("NO");
		}
	}

}
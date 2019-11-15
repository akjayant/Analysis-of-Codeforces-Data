#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

// 어떻게 내는 게 이득이지?
char s[100001];
int dp[100001];
int n;
int go(int o) {
	if (o == n) return 1;
	if (dp[o] != -1) return dp[o];

	int ret = 0;
	if (o != n - 1 && s[o] == 'u' && s[o + 1] == 'u') ret += go(o + 2);
	if (o != n - 1 && s[o] == 'n' && s[o + 1] == 'n') ret += go(o + 2);
	if (s[o] == 'm' || s[o] == 'w') {
		printf("0");
		exit(0);
	}
	ret += go(o + 1);

	return dp[o] = ret % MOD;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s", s);
	n = strlen(s);

	printf("%d", go(0));
}
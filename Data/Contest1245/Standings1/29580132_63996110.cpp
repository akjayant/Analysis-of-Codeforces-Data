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
int inp[300005];

int main() {
	scanf("%d", &N);
	while (N--) {
		int a, b; scanf("%d %d", &a, &b);
		if (__gcd(a, b) == 1) {
			printf("Finite\n");
		}
		else puts("Infinite");
	}


}
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
#define MAX(x, y) ((x) > (y) ? (x):(y)) 
#define MIN(x, y) ((x) > (y) ? (y):(x))
#define ABS(x) ((x) > 0 ? ((x) : -(x)))
using namespace std;
const int MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;

int main()
{
	int i, j, x;
	ll a, b, c, d;
	int T;
	scanf("%d", &T);
	while (T--) {
		a = b = c = d = 0ll;
		scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &x);
			if (x & 1) ++a;
			else ++b;
		}
		scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d", &x);
			if (x & 1) ++c;
			else ++d;
		}
		printf("%lld\n", a*c + b * d);
	}

}